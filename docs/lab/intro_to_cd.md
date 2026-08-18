---
layout: default
---

# Intro to Computational Design

2026 \| Computational design \| Rhino / Grasshopper / Python / Cpp

An introduction to computational design using Rhino, Grasshopper, and Python. Covers three core modeling approaches in Rhino, external communication with Python 3, and Model Context Protocol (MCP).

---

## 1. 概要

### 1.1 ゴール

- モデリングアプローチの比較
- Python 3 と外部通信
- MCP

### 1.2 用語

フォーカスするポイントの異なる様々な言葉があります。⚠️使う人や文脈によって意味が変わります。

| 用語 | 定義 |
| --- | --- |
| **CAD (Computer Aided Design)** | コンピューターを用いた設計・デザイン手法全般。 |
| **Computational Design** | 計算能力や数理的アプローチをデザインプロセスに統合する手法の総称。 |
| **Algorithmic Design** | 論理的・数理的手順（プロセス）を組み立てることに着目。 |
| **Procedural Design** | 大体同じ。 |
| **Parametric Design** | （アルゴリズムを組んだ上で）パラメーター操作で形状を制御することに着目。 |
| **Generative Design** | 制約条件とゴール（荷重、重量、製造要件等）を設定し、アルゴリズムやAIに最適解を自律探索・生成させる手法。 |

> **Parametric Architecture**
> 
> - 一般的には… 単なる「Grasshopper等を用いた複雑・有機的な建築造形」
> - 「日照、風向、構造負荷等の多角的環境パラメーターを統合した最適化プロセス」と主張する人もいる
> - ザハ・ハディド・アーキテクツのパトリック・シューマッハ氏が21世紀の建築様式「Parametricism」として提唱（参考：[A simple guide to parametricism](https://www.dezeen.com/2026/05/06/parametricism-simple-guide/)）

> **Generative Design**
> 
> - 従来手法との違い: パラメトリック（人間が定義したルール内の変形）に対し、ジェネレーティブ（条件を満たす未知の形状の自律創出）。
> - アプローチ: 設計者が制約（荷重・固定点・製法）を入力し、AI・アルゴリズムが数百の最適解を生成。
> - 製造分野では、Autodesk Fusionによる構造の最適化や軽量化が代表例。
  - [Unlocking Innovative Solutions with Generative Design](https://www.autodesk.com/products/fusion-360/blog/unlocking-innovative-solutions-with-generative-design/)
  - [ものづくりにおけるジェネレーティブ デザインの 8 つの価値を探る](https://www.autodesk.com/products/fusion-360/blog/ja/generative-design-manufacturing-values/)

### 1.3 モデリングアプローチ

- **手動操作**: 直感的な単発操作。反復作業やバリエーション検討には非効率。
- **Visual Programming**: ノード接続によるデータフロー構築。ルール再利用とリアルタイム形状検証が得意。
- **Script**: Python/C#等のテキストコード記述。複雑なループ処理やデータ処理、AI連携に最適。

### 1.4 Rhinoceros

- ライセンス価格（買い切り）
    - 商用版（フルライセンス）: ¥187,000
    - 教育版（学生・教員向け）: ¥39,600（機能制限なし）
    - アップグレード商用版: ¥110,000
- 90日間無料評価版
    - 公式サイト：[rhino3d.com](https://www.rhino3d.com/)
    - 90日間の無料トライアル（Grasshopperを含め商用版と同じフル機能）
    - 試用期間（90日）終了後もビューアー（モデルの閲覧・各種検証）として利用可能（保存不可）

[<img src="https://static.food4rhino.com/cdn/farfuture/kVBvPnsEt2xDkLdUvD_PYXboGrtv_4ONmW_AJ1d4TWA/mtime:1680618717/sites/default/files/public/f4r/images/rh2.png" style="width: 600px;" alt="">](https://www.food4rhino.com/en)

<!---
### 1.5 Autodesk Fusion

- 個人用無償ライセンス（Personal Use）
    - [Autodesk Fusion](https://www.autodesk.com/jp/products/fusion-360/overview#top)：「個人用 Autodesk Fusion」からアクセス（少し目立たないように書いてある）
    - 条件: 非商用目的（趣味・DIY・個人の学習等）かつ年間収益1,000米ドル未満の場合、無償で継続利用可能。
    - 主な制限: 同時編集可能ドキュメント数（10個まで）などの制限がある。
--->

---
## 2. Grasshopper

### 2.1 コンセプト

- **コンポーネント:** 関数/処理ノード。左側（Input）からデータを受け取り、右側（Output）から出力する。
- **ワイヤー:** コンポーネント間のデータ伝達パス。
- **パラメーター:** 入力変数（数値スライダー、ジオメトリ参照など）。

### 2.2 主要操作

1. **起動・ファイル:** コマンド `Grasshopper` / 拡張子 `.gh`
2. **コンポーネントの呼び出し:** メニュータブ選択、またはキャンバスダブルクリックによるキーワード検索（例：`Sphere` で球体生成、`10.0` でスライダー生成、`//` でパネル生成等）。
3. **ノード操作:**
    - 通常ドラッグで接続
    - `Shift` + ドラッグで複数接続（上書き防止）
    - `Ctrl` + ドラッグで接続解除
4. **コンポーネントの制御（右クリック）:**
    - `Enabled / Disabled`: 処理の有効化/無効化
    - `Preview`: ビューポートでの描画ON/OFF
    - `Bake`: ジオメトリのRhinoオブジェクト化
5. **Bake（ベイク）:**
    - Gh上で操作中のジオメトリは「一時的なプレビュー表示」。
    - `Bake`を実行することで、通常のCAD要素として空間に「焼き付け」される。
    - **注意点:** Bake後の要素はGh側のパラメーター変更と連動しなくなる。
6. **端子（入力・出力）の動的制御（ズーム操作）:**
    - **端子の増減（`Merge`, `Entwine`, `Python` 等）:**
        - コンポーネントに一定以上近づく（ズームインする）と、端子付近に「**`+`** / 」アイコンが表示される。
        - 「`+`」をクリックで接続ポイントを追加、「」で削除が可能。
    - **端子の設定・カスタマイズ（端子を右クリック）:**
        - データ構造の直接変更（*Flatten*, *Graft*, *Simplify* 等のデータプリセット適用）。
        - 端子名（変数名）の変更や、入力データ型の指定（Type Hinting）。

### 2.3 データ構造（データツリー）

他プログラミング言語の「多次元配列」「ネストされたリスト」に相当するGh独自の概念です。使っているとなんとなくわかってきます。

**参考:** [Lesson 3 - Data structures](https://interactivetextbooks.tudelft.nl/rhino-grasshopper/Grasshopper_Rhino_course/1_Lessons/3_Lesson_3_-_Data_structures/%21index.html#data-trees)

- **List (リスト):** 単一の配列 `[A, B, C, D]`
- **Data Tree (データツリー):** パス（階層アドレス）を持つネスト構造 `Path{0}: [A, B]`, `Path{1}: [C, D]`
- **マッチング原則:** 原則として「同じパス（階層）・同じインデックス」の要素同士がペアで処理される。
- **主要なデータ構造操作ノード:**
    - `Flatten`: すべての階層を解体し、単一のリスト（1次元配列）に平坦化する。
    - `Graft`: 各要素に固有の新しい枝（1階層深いパス）を割り当て、個別処理を可能にする。
    - `Simplify`: データ処理に関与しない無駄な親階層パスを削除・整理する。
    - `List Item`: 配列内の指定インデックス要素を取得する。
    - `Merge`: 複数のデータストリームをルールに沿って統合する。

![](/docs/images/lab/intro_to_cd/data.jpg)

### 2.4 Grasshopperの学習
基本的な操作を学習したら、作りたいものを作りながら学習していくのが効果的。

**Grasshopperリソース:**
- [Grasshopper Docs](https://grasshopperdocs.com/)
- [AppliCraft \| Grasshopper Component Index](https://www.applicraft.com/ghcp_index/)

**チュートリアル:**
- [Delft University of Technology \| Computational Design for (Industrial) Designers using Rhino Grasshopper](https://interactivetextbooks.tudelft.nl/rhino-grasshopper/Grasshopper_Rhino_course/intro.html)
- [Gediminas Kirdeikis \| Grasshopper for Beginners - Full Course](https://youtu.be/b0elmzjWlE8?si=eA_W1YUuaxSRDSnT)
- [Junichiro Horikawa \| Grasshopper Tutorials](https://youtube.com/playlist?list=PLzRzqTjuGIDiOSybLxZ4DiSaRYdVdDnMJ&si=pMAyUFsnnJt1V_ey)

**参考書籍:**
- [Parametric Design with Grasshopper［改訂第3 版］](https://bnn.co.jp/products/9784802513104)
- [AAD Algorithms-Aided Design](https://teaching.arturotedeschi.com/?page_id=6691)

> **AIを使った学習:**
- Grasshopperはドキュメントが豊富でコミュニティも活発なため、多くの場合AIに質問することで適切な回答を得ることができます。
- Grasshopper定義を通常の`.gh`ではなく`.ghx`形式（XMLベースのプレーンテキスト）で保存すると、AIが解析できるようになります。

> **Find Component:** コンポーネントを `Ctrl + Alt` を押しながらクリックすると、そのコンポーネントが上部タブのどこにあるかを赤い矢印で視覚的に教えてくれる。

> **拡張プラグイン集: [Food4Rhino](https://www.food4rhino.com/en)**
> 
> Grasshopperには、様々な機能を拡張するプラグインがあり、Food4Rhino で多くのツールを探すことができます。用途に応じて既存のプラグインを導入すれば、解析、生成、インタラクション、製造支援など、幅広いワークフローに対応できます。

---
## 3. Rhino Script

### 3.1 実行手順・ライブラリ

1. **環境の起動と実行手順**

    Rhino、Grasshopperどちらからもスクリプトを利用することができます。Rhino上ではバッチ処理・自動化、Grasshopper上ではノード機能の補完・パラメトリックなデータ処理としてスクリプトを利用します。

    - **Rhino上で実行する（ワンショット自動化）**
        - `メニュー → ツール → スクリプト → 編集` でスクリプトエディタ（Rhino 8では Script）を起動。
        - コード記述・実行により、Rhino空間のオブジェクトを直接生成・編集。
        - `.py` ファイルとして保存し、単体コマンドやツールボタンに割り当てて再利用可能。
    - **Grasshopper上で実行する（動的・パラメトリック処理）**
        - キャンバス上に `Python 3 Script` コンポーネントを配置。
        - コンポーネントの入力端子（x, y等）からデータを受け取り、処理結果を出力端子（a等）へ渡す。
        - キャンバス上のパラメーター変更に応じてスクリプトがリアルタイムに再計算される。
        - **入力・出力端子の名前と型（`int, Line, Brep`など）は、スクリプト内の変数に合わせる必要があります。**

1. **主要ライブラリ**

    Rhino機能の操作、および外部データ処理を行うための主要ライブラリ。

    | カテゴリ | ライブラリ | 概要・用途 | リンク |
    | --- | --- | --- | --- |
    | **Rhino操作** | `rhinoscriptsyntax` | Rhinoコマンドに相当する操作を直感的に記述できる高レベル・ラッパー関数群。 | [RhinoScriptSyntax](https://developer.rhino3d.com/api/RhinoScriptSyntax/) |
    |  | `Rhino.Geometry` (`RhinoCommon`) | ジオメトリを直接扱う下層コアAPI。高度な幾何計算や高速処理向け。 | [RhinoCommon API](https://developer.rhino3d.com/api/rhinocommon/) |
    |  | `ghpythonlib.components` | Grasshopperの既存ノード機能をPythonコード内から直接呼び出して実行。 | [Node in Code from Python.](https://developer.rhino3d.com/guides/rhinopython/ghpython-call-components/) |
    | **その他** (Rhino 8 / Python 3) | 標準ライブラリ | `math`（数値計算）、`random`（乱数生成）、`json` / `os`（ファイル処理）など。 | |
    |  | 外部CPythonライブラリ | NumPy, SciPy, Pandas, PyTorch等。`# env: numpy` 等の記述で読み込み可能。 | |

### 3.2 Rhinoスクリプトのアーキテクチャ

1. **ライブラリの階層**

    | レイヤー | コンポーネント | 役割・技術スタック |
    | --- | --- | --- |
    | **最上層 (ユーザー記述)** | **スクリプト** | **Python 3 / C#**: ユーザーやAIが記述するコード領域。 |
    | **高レベル処理** | **rhinoscriptsyntax** | **Pythonラッパー**: RhinoCommonを初心者向けに簡易化した関数群。 |
    | **共通API層** | **RhinoCommon** | **.NET Core API**: Rhinoの全機能にアクセスする公式クロスプラットフォームAPI。 |
    | **最下層 (コアエンジン)** | **Rhino Kernel** | **C++ ネイティブエンジン**: 幾何演算・描画を高速処理するRhino本体。 |

1. **動作言語**

    | 言語 | 特徴・用途 | Rhinoでの位置付け |
    | --- | --- | --- |
    | **Python 3 (CPython)** | AI/LLMとの親和性が極めて高く、外部ライブラリ統合が容易。 | **現在の推奨標準環境** (Rhino 8〜) |
    | **Python 2 (IronPython)** | 旧Rhino 7までの標準（.NET上で動作するPython実装）。 | 互換性維持目的の旧環境 |
    | **C#** | 高度なプラグイン・カスタムコンポーネント開発用。 | 開発者向けネイティブ環境 |
    | **VBScript** | 旧世代のRhinoScript。 | **非推奨** |

    > **バイブコーディング:**
    - ハルシネーション（存在しない関数の捏造など）を防止するため、試行環境（例: `Rhino 8 / Python 3`）とライブラリ（`rhinoscriptsyntax`）を指定
    - エラー発生時はエラーメッセージを返しデバッグ

### 3.3 スクリプトデモ例：フラクタルツリー（再帰処理）

1. **概要**
    再帰関数と乱数を用いた幾何生成デモです。Grasshopper（動的パラメーター制御）と Rhino単体（直書きワンショット実行）の両方で検証できます。

    <div class="media-wrapper">
        <video src="/docs/images/lab/cd_lab/fractal.mp4"
        autoplay
        muted
        loop
        playsinline></video>
    </div>

1. **Grasshopper上での実行手順**
- キャンバスに `Python 3 Script` コンポーネントを配置。
- 端子設定（右クリックし、名前と型を変更）
- コンポーネント内にコードを貼り付け、Inputにスライダーを繋いでライブ操作。

    | | 名前 | 型 | 目的 |
    | --- | --- | --- | --- |
    | Input | `gen` | Integer | 世代数制限 |
    | | `angle` | Float | 分岐角 |
    | | `scale` | Float | 縮小比 |
    | Output | `Lines` | Line | アウトプット |

1. **Rhino上での実行手順**
  - `メニュー → ツール → スクリプト → 編集` でエディタを開き、コードを貼り付けて直接実行。

1. **Pythonコード（Rh/Gh共通）**

    ```py
    import rhinoscriptsyntax as rs
    import random

    # 入力変数の初期化 (Rhino単体実行用)
    gen = globals().get('gen', 6)
    angle = globals().get('angle', 25.0)
    scale = globals().get('scale', 0.8)
    seed = globals().get('seed', 42)

    random.seed(seed)
    Lines = []

    # 幹の生成
    A, V = [0, 0, 0], [0, 0, 1]
    B = rs.PointAdd(A, V)
    Lines.append(rs.AddLine(A, B))

    # 再帰分岐関数
    def Grow(pt, v, s, a, g):
        if g >= gen: return
        v = rs.VectorScale(v, s)
        plane = rs.PlaneFromNormal(pt, v)
        circle = rs.AddCircle(plane, 0.1)
        t = rs.CurveClosestPoint(circle, A)
        rot_axis = rs.VectorCreate(pt, rs.EvaluateCurve(circle, t))

        for sign in [-1, 1]:
            V_next = rs.VectorRotate(v, sign * a + random.uniform(-3, 3), rot_axis)
            pt_next = rs.PointAdd(pt, V_next)
            Lines.append(rs.AddLine(pt, pt_next))
            Grow(pt_next, V_next, s, a, g + 1)

    Grow(B, V, scale, angle, 0)
    ```

### 3.4 スクリプトのコマンドボタン化

作成した `.py` スクリプトをRhinoのコマンドにできます。

1. 保存: コードを `.py` 形式でローカル（任意フォルダ）に保存し、ファイルの絶対パスをコピー。
2. ボタン作成: ツールバーの空白領域で右クリック → `新規ボタン` を選択。
3. マクロ設定: コマンド欄に `! _-RunPythonScript "ファイルの絶対パス"` と入力して保存。
    - (注: `_-` はダイアログをスキップして即時実行させるための記述)

---
## 4. モデリングアプローチ比較

| 項目 | 手動操作 | Grasshopper | スクリプト |
| --- | --- | --- | --- |
| **操作** | CLI・マウスによるGUI操作 | ノード接続（ビジュアルプログラミング） | テキストコード（Python/C#） |
| **強み** | 直感的、事前のロジック設計不要 | 構造視認性が高い、リアルタイム検証 | バッジ処理、ループ/条件分岐 |
| **弱み・リスク** | 大量処理・仕様変更時の工数大 | 複雑化による**スパゲッティコード**化 | 構文・APIの習得コスト |
| **AI(LLM)親和性** | 極めて低い | 低い（グラフ構造生成の難しさ） | **極めて高い**（コード生成領域） |

> **効率化の思考フレーム: [The 5-Step Algorithm (Elon Musk)](https://youtu.be/tdf3luOCNks?si=3qhKdoTCu-iDgWp9)**
> 
> Ghやスクリプトで自動化する前に… 「自動化する必要がないことを自動化していないか？」
> 
> 1. **要件を疑え:** 前提仕様そのものの不必要性を検証する。
> 2. **プロセスを削除せよ:** 不要な工程を破棄する。
> 3. **単純化・最適化せよ:** 残った工程をシンプルにする。
> 4. **サイクルタイムを加速させよ:** 処理速度を向上させる。
> 5. **自動化せよ:** 上記を経た上で最終手段として自動化を導入する。

---
## 5. 応用例

### 5.1 Rhino外部通信: IMU・超音波センサーを使ったメッシュ変形システム

1. **概要**

    センサーからのデータをGrasshopperに入力し、3Dジオメトリーをリアルタイムに変形させるインタラクティブな造形システムです。

    - IMUの傾きに合わせたメッシュのフロー変形
    - 超音波センサーによる距離連動パラメータ: 
        - 距離が近い場合: 細かい波
        - 距離が遠い場合: ゆったりした波

    **ファイル:** [GitHub Repository](https://github.com/hayashnaoki/rhino-physical-interface/tree/main/io_tests)

    <div class="media-wrapper">
        <video src="/docs/images/lab/intro_to_cd/imu_sonic_serial.mp4"
        autoplay
        muted
        loop
        playsinline></video>
    </div>

    **システム**
    ```
    [ 物理世界 / センサー ]
    │ MPU-6050 (IMU)    : 運動 / 姿勢変化
    │ HC-SR04 (超音波)   : 手の距離 (分圧：Echo → [1kΩ] → D3 ← [2kΩ] GND)
    ▼
    [ 信号処理・マイコン (XIAO RP2040) ]
    │  - センサ読み取り ＆ 重力補正フィルター
    │  - CSVテキスト成形 ("lin_ax,lin_ay,lin_az,gx,gy,gz,dist\n")
    ▼
    ════════════════════════════════════════════
        USB Serial 通信 ( Baudrate: 115200 )
    ════════════════════════════════════════════
    ▼
    [ 視覚化・CAD (Rhino 8 / Grasshopper) ]
    └─ [ GH Python Component ]
            - pyserial でリアルタイムデータ受信
            - 距離データ ──> メッシュ表面の2軸波紋生成
            - 運動データ ──> 全体のひねり・伸縮（Transform）変形
    ```

1. **ハードウェア**

    - 使用部材
        - マイコン: XIAO RP2040
        - IMU: MPU-6050 (6軸: 加速度3軸 + ジャイロ3軸)
        - 超音波距離センサー: HC-SR04
        - 分圧抵抗: 1 kΩ, 2 kΩ (各1本)
    
    - ピンアサイン
        
        HC-SR04のEcho信号（5Vロジック）をXIAOの耐圧（3.3V）に合わせるため、1kΩ / 2kΩの抵抗による分圧回路を使用（**`Echo → [1kΩ] → D3 ← [2kΩ] GND`**）。

        | モジュール | ピン名 | XIAO 接続ピン | 補足 |
        | --- | --- | --- | --- |
        | **HC-SR04** | VCC | 5V | 5V電源供給必須 |
        |  | Trig | D2 | GPIO（トリガーパルス出力） |
        |  | Echo | D3 | **分圧回路を経由** |
        |  | GND | GND | |
        | **MPU-6050** | VCC | 3V3 | |
        |  | SDA | D4 | I2C |
        |  | SCL | D5 | I2C |
        |  | GND | GND | |

1. **ファームウェア**

    センサーデータの取得と初期処理を担います。

    - 環境: PlatformIO (C++)
    - 処理内容:
        - MPU-6050から加速度・角速度を取得。
        - HC-SR04から距離データ（cm）を計測。
        - 重力影響カットのため、加速度データへハイパスフィルター（HPF）を適用。
        - シリアル出力: 115200 bps（CSV形式：`lin_ax,lin_ay, lin_az, gx, gy, gz, dist\n`）

1. **Grasshopper概要**

    XIAO RP2040に接続した6軸IMU（MPU-6050）からのセンシングデータを、ファームウェア経由でシリアル通信、Rhino GrasshopperのPython（`pyserial`）でリアルタイム受信、3Dジオメトリーを編集。

    | 処理工程 | スクリプト / コンポーネント | 処理概要・詳細 |
    | --- | --- | --- |
    | データ受信 | `imu_sonic_serial.py` | `pyserial` でUSBシリアル経由でデータを受信・パース。 `Trigger` コンポーネント（100ms周期）によりGHキャンバスを自動更新。パラメータ（ポート `/dev/cu.usbmodem14101`, ボーレート `115200`）は書き換え可能。 |
    | ベース形状 ＆ Flow変形 | - | 回転体（Revolve）生成後、`QuadRemesh` でメッシュ化。IMUの `gravity_vec`（重力ベクトル）を用い、傾き方向へFlow変形。 |
    | 波紋テクスチャ生成 | `mesh_wavy_deform.py` | 直交する2軸のSine波（Ocean Wave）を法線方向へ付与。 `distance` 連動: **近い**＝振幅が大きい ＋ 波長が短い（細かな波）、**遠い**＝振幅が小さい ＋ 波長が長い（緩やかな波）。 |
    | 最終出力 | - | `SubD from Mesh` で滑らかなSubDサーフェスとして出力。 |

    **Ghポイント**

    - 外部ライブラリの自動ロード（インラインディレクティブ）
        - Rhino 8のPython 3環境では、スクリプト冒頭に `# r: <package_name>`（例: `# r: pyserial`）を記述することで必要な外部ライブラリが自動的にロードされます（`pip install`などは不要）。
    - Grasshopper側における再計算トリガー`Trigger`の役割
        - Grasshopperでは通常「パラメータの変化時のみ」再計算されます。
        - `Trigger`コンポーネントを接続することで一定周期（例: 100ms）で定期的にコンポーネントを再計算させ、ジオメトリを更新し続けます。
    
    ![](/docs/images/lab/intro_to_cd/imu_sonic_serial.jpg)

---

### 5.2 G-code生成 & 送信 (Slicer & Sender)

1. **概要**

    スライサーソフトを使わず、Grasshopperで直接G-codeを生成するワークフローにより、非平面パスや吐き出し量の調整など、様々なカスタマイズが可能になります。

    **ファイル:** [GitHub Repository](https://github.com/hayashnaoki/rhino-physical-interface/tree/main/gcode_tests)


    <div class="media-wrapper">
        <video src="/docs/images/lab/intro_to_cd/gcode.mp4"
        autoplay
        muted
        loop
        playsinline></video>
    </div>

1. **スライサー**

    **Gh定義（非平面パスの例）:**
    - `Geometry → Curve → Point → XYZ Coordinate`へ変換
    - Geometry上に波状のCurveを作成
    - Curveを分解しPointを作成、XYZ座標に変換
    - 移動距離に対応した押し出し量（`E`）の計算（`吐出し面積 / フィラメント断面積 * 移動距離`）
    - G-code としてフォーマット、スタートプロトコル・エンドプロトコルを連結（`Concatenate`）

    ![](/docs/images/lab/intro_to_cd/gh_slicer.jpg)

    **G-code 例:** `G1 F1200 X110 Y90 Z0.2 E0.2`

    | `G0` / `G1` | `F` | `X Y Z` | `E` | `; Comment` |
    | 移動を初期化（非押出移動にはG0、押出移動にはG1） | フィードレート（移動速度）（mm/min） | 座標（mm） | 移動単位ごとの押出量（mm） | セミコロン以降のテキストは無視（コメントや説明用） |

    **BambuLab SDカード補足:**
    - マイクロSDカード
        - 取り外し: `設定 → SDカード → 取り外し`
        - `.gcode`をマイクロSDカードのルートディレクトリに入れる
        - 印刷: ファイル → 2つ表示されるうち、右側を選択 → 開始（左側は隠しファイル`._~~~.gcode`）
    - Bambu Studio `.3mf`ファイル
        - 拡張子は `.3mf` （あるいは `.gcode.3mf`）だが中身は、G-codeやサムネイル画像、設定ファイルを圧縮した「Zipアーカイブ」 
        - 拡張子を `.zip` に変えると解凍できる

    **サンプルG-codeの仕様:**
    - 対象機種：Bambu Lab A1 mini
    - ノズル径：0.8 mm
    - フィラメント：1.75 mm PETG

    ![](/docs/images/lab/intro_to_cd/gcode_test.jpg)

    > **Start / End Protocol**
    >
    > 印刷開始前の準備動作、印刷完了後の安全停止動作のコマンド。プリンターにより異なるので、スライサーソフトで生成されるG-codeを流用・解析する必要があります。
    >
    | コマンド例 | 分類 | 指示 |
    | --- | --- | --- |
    | `G1` | 移動制御 | 指定した速度（F値）で直線移動（E軸指定時は樹脂押し出しを伴う） |
    | `G28` | 原点復帰 | 設定された全軸（X, Y, Z）のホームポジションへの移動・原点確定 |
    | `G90` | 座標指定 | 絶対座標指定モードへの切り替え（原点を基準とする移動） |
    | `G91` | 座標指定 | 相対座標指定モードへの切り替え（現在地を基準とする移動） |
    | `G92` | 座標設定 | 現在位置の座標値（E軸など）を指定した値へ再設定・リセット |
    | `M106` | ファン制御 | パーツ冷却ファンの出力設定・作動 |
    | `M140 / M104` | 加熱制御 | ベッド / ノズルの目標温度を設定（非ブロッキング／到達を待たずに次行へ） |
    | `M190 / M109` | 加熱制御 | ベッド / ノズルの目標温度設定と到達待機（ブロッキング／指定温度まで停止） |
    | `M420` | ベッド補正 | 自動ベッドレベル補正データの読み込み・有効化 |
    | `M84` | モーター制御 | ステッピングモーターの給電（励磁）をオフにする |

1. **G-codeセンダー（WIP）**

    さらに、ローカルネットワーク（Wi-Fi）接続したBambuLabプリンターを、GhからMQTTサーバーを介してG-codeを送付できないか検討中…

**参考:**
- [Advanced 3D Printing with Grasshopper®: Clay and FDM](https://www.food4rhino.com/en/resource/advanced-3d-printing-grasshopper-clay-and-fdm)
- [TU Delft \| Generating 3D printing files (G-code) with Grasshopper](https://interactivetextbooks.tudelft.nl/rhino-grasshopper/Grasshopper_Rhino_course/2_Knowledge_base/Digital_fabrication/3D_Printing/%21index.html)
- [RepRap \| G-code](https://reprap.org/wiki/G-code)
- [自作GcodeをBambulabの3Dプリンターで出力する方法](https://note.com/triplebottomline/n/n19992343d3af)

---
## 6. MCP（Model Context Protocol）

### 6.1 概要とトレンド変化

- **従来:** 「AIがアイデア/コードを出力 → 人間がCAD上で手動実行・検証」。
- **現在 (MCP環境):** 「AIエージェントがMCP経由でCADのAPIを直接叩き、生成・検証・修正まで自律実行」。
- **MCPの役割:** LLMと外部ツール（CAD等）を標準化されたプロトコルで接続するローカルミドルウェア。

### 6.2 主要ツールの最新動向

| ソフト | MCPツール | 主な特徴・機能 | リンク |
| --- | --- | --- |
| Rhino | Rhino MCP (McNeel公式) | GitHubにて公式プラットフォーム開発が進行中。レイヤー操作やスクリプト動的実行ツールを展開。 | [Rhino MCP Platform](https://mcneel.github.io/RhinoMCP/) |
| Rhino | 3rd party | サードパーティ開発者によるMCPサーバープラグイン。プラグインコミュニティ[Food4Rhino](https://www.food4rhino.com/en)やGitHubなどで公開。 | 例：[rhinomcp (by ccc159)](https://www.food4rhino.com/en/app/rhinomcp) |
| Grasshopper | Raven | Grasshopperのグラフ構造（ノード配置・配線）自体をAIに自動生成・最適化させるプラグイン。 | [Raven](https://www.raven.build/en) |
| Autodesk Fusion | Fusion MCP | Anthropicとの共同開発。自然言語指示（パラメーター変更、フィーチャー操作等）でAPIを実行しモデリングを完了。アドイン開発のペアプログラミング用途でも活用。 | [Fusion MCP](https://aps.autodesk.com/blog/bringing-fusion-claude-creative-work) |
| Blender | Blender MCP | Python APIとの親和性の高さを活かし、オブジェクト配置、マテリアル・ライティング設定まで会話型で自動化するアドオンがコミュニティ主導で急増。 | [MCP Server](https://www.blender.org/lab/mcp-server/) |

### 6.3 Rhino MCP のシステム構成・通信フロー

| レイヤー | 主要コンポーネント | 役割と通信プロトコル |
| --- | --- | --- |
| **クライアント層** | **AIクライアント** *(Claude / Cursor / Gemini 等)* | ユーザーの自然言語指示を受け取り、ツール呼び出し（Tool Call）を生成するUI/エディタ環境。 |
| **中継・変換層** | **MCPサーバー** *(Python / FastMCP 等のローカルミドルウェア)* | 標準規格（**stdio / JSON-RPC**）を解釈し、AIからの要求をCAD専用の命令形式に変換・中継する橋渡し役。 |
| **エンドポイント層** | **Rhinoプラグイン** *(C# RhinoCommon / Python 常駐リスナー)* | ローカル通信（**TCP Loopback / Socket / 127.0.0.1:10501**）でメッセージを受信し、Rhino側で常駐待機する受信用ソケット。 |
| **実行層** | **Rhino / Grasshopper Kernel** | 受信した命令に基づき、Rhino/Grasshopper内部でスクリプトの動的実行やジオメトリの直接生成・操作を実行。 |

1. **AIクライアント:** ツール仕様（JSON Schema）に基づき、プロンプトを解釈して実行命令を発行。
2. **MCPサーバー:** AIのJSON要求とCAD側の通信プロトコルを相互翻訳・中継。
3. **Rhinoプラグイン:** 受信した命令をRhinoのメインスレッド上で動的実行し、結果（成功/エラー/状態）を返答。

### 6.4 CAD MCPの課題とインプリケーション

- **技術的課題・制限:**
    - 3D空間認識能力の不足: LLMの3Dトポロジーや厳密な空間座標、美観理解は発展途上。
    - コンテクストの壁: 大規模アセンブリではすぐにデータ量がトークン上限を超えるため、「選択中のオブジェクトのみ取得」「バウンディングボックスや軽量なメタデータのみ送信」などの対策が必要。
    - パフォーマンス: 大規模処理時にAIが愚直なAPI呼び出しを行うため、遅延計算（「スクリプトを一括生成してバッチ実行させる」「Redraw（画面再描画）を抑制する」）などの指示が必要。
- **安全性の懸念・新たな技術負債:**
    - ブラックボックスノード化: AIによるGh定義生成や、Gh内スクリプトを多用すると、Gh本来の「視覚的データフロー」が失われ、人間によるデバッグが不可能になるリスク。
    - 意図しない形状破壊: 自律実行によるスケッチ拘束の不具合や、製造不可能な自己交差形状の生成リスク。
- **インプリケーション:**
    - 設計者の役割は「操作」から「制約条件の定義」および「AIが提示するバリエーションのディレクション」へ移行。
    - 解析（CAE）等と組み合わせた自律型最適化ループ構築。
      - 生成 (Generation): MCP経由でLLMがRhino/GH上に形状を生成。
      - 解析 (Evaluation): 構造解析（FEA）や環境シミュレーションツールをMCPで呼び出して評価。
      - 自動修正 (Refinement): 「応力集中が発生している箇所」のエラーログをLLMが読み取り、自律的にフィレット半径や肉厚パラメータを調整して再実行。



<!---

## 1. 概要と整理

### 1.1 目的

- **ハードルを下げる:** つかってみる。
- **手順の構築:** モデリングする手順を設計する感覚を養う。
- **AI連携への理解:** MCP（Model Context Protocol）などのAI活用プロセスの基盤を理解する。

### 1.2 言葉の定義と整理

フォーカスするポイントの異なる様々な言葉があります。文脈によって異なる意味合いを持ち、互いに重なり合う曖昧な概念です。

- **CAD (Computer Aided Design):** コンピューターを用いた設計・デザイン手法全般。
- **Computational Design:** 計算能力や数理的アプローチをデザインプロセスに統合する手法の総称。
- **Parametric Design:** 要素間に寸法や位置などの明確な関係性（ルール）を構築し、変数（パラメーター）の操作によって形状を制御する手法。
- **Algorithmic Design / Procedural Design:** 論理的・数理的な一連の手順（プロセス）を組み立てることで、形状を制御・出力する手法。
- **Generative Design:** 構造強度、重量、製造要件などの制約条件（ゴール）のみを設定し、アルゴリズムやAIによって最適解を自律的に探索・生成させる手法。

> **Parametric Architecture**
> 
> - 一般的には「Grasshopperなどを活用した複雑で有機的な建築造形」として認知されています。
> - 本質的には、日照、風向、構造負荷などの多角的な環境パラメーターを統合した最適化プロセスを指します。
> - 建築家パトリック・シューマッハ（ザハ・ハディド・アーキテクツ）は、これを21世紀の建築様式「Parametricism」として提唱しています。
  - [A simple guide to parametricism](https://www.dezeen.com/2026/05/06/parametricism-simple-guide/)

> **Generative Design**
>
>- 従来のパラメトリックデザインが「人間の定義したルールに基づく変形」であるのに対し、ジェネレーティブデザインは「条件を満たす未知の形状の創出」を目指します。
> - 荷重、固定箇所、材料、製造方法（3Dプリントや5軸加工など）といった「制約条件とデザインゴール」を設計者が入力し、AIと数理アルゴリズムが何百もの最適解を自律的に探索・生成（Generate）するアプローチです。
> - 製造分野では、Autodesk Fusion（旧Fusion 360）による構造の最適化や軽量化が代表例です。
  - [Unlocking Innovative Solutions with Generative Design](https://www.autodesk.com/products/fusion-360/blog/unlocking-innovative-solutions-with-generative-design/)
  - [ものづくりにおけるジェネレーティブ デザインの 8 つの価値を探る](https://www.autodesk.com/products/fusion-360/blog/ja/generative-design-manufacturing-values/)

### 1.3 Rhino上で使えるツール

Rhinoでは、複数の操作方法が存在します。

- **手動操作 (Manual):** マウスやコマンド入力によって1つずつ配置する方法です。直感的で手軽ですが、反復作業や多数のバリエーション作成には工数がかかります。
- **Grasshopper (Visual Programming):** コンポーネントをワイヤーで接続し、パラメーターの変化に応じて形状を更新する方法です。データの流れを視覚的に把握しやすく、設計ルールを再利用しやすい特徴があります。
- **スクリプト (Script):** Pythonなどのコードを用いて処理を記述する方法です。複雑なループ処理や大量データの自動化に向いており、AIとの親和性も高いです。

---
## 2. Grasshopper入門

### 2.1 基本概念

- **コンポーネント:** Rhinoにおけるコマンド。入力（左側）を受け取り、内部処理を行い、出力（右側）を返す。
- **ワイヤー:** コンポーネント間でデータを伝達するための経路。
- **パラメーター:** 数値スライダー（Number Slider）など、リアルタイムに変更可能な変数。

### 2.2 基本操作ルール

1. **Grasshopperの起動:** 
  - **[ツール] ──> [Grasshopper]** を選択、またはコマンド欄に **`Grasshopper`** と入力
  - Grasshopperのファイル形式: `.gh`
  - 既存の `.gh` ファイルは **[File] ──> [Open]** で開く
2. **コンポーネントの呼び出し:**
    - **タブから選択:** 画面上部のメニュータブ（Params, Math, Sets, Vector, Curve, Surfaceなど）から、機能に応じたアイコンを選択する。
    - **ダブルクリック検索:** キャンバスの空白部分を左ダブルクリックし、キーワード（例: `ConstructPoint`, `Line`）を入力してダイレクトに呼び出す。特殊な例として、`10.0` などの数値でNumber Slider、`//`でPanelを呼び出すことができる。
3. **ワイヤーの接続と解除:**
    - **単一接続:** 出力端子から次の入力端子へドラッグ&ドロップして接続する。
    - **複数接続:** すでにワイヤーが接続されている入力端子に対し、`Shift` キーを押しながら新しいワイヤーを重ねることで、上書きせずにデータを追加できる。
    - **接続解除:** `Ctrl` キーを押しながら接続済みの端子に向かってドラッグすることで、配線を解除できる。
    
4. **右クリックによる操作:**
    - コンポーネントの中央右クリック:
      - `Name`: コンポーネント自体の名称を変更する。
      - `Enabled / Disabled`: 処理の有効/無効を切り替える（無効にすると下流の処理もストップする）。
      - `Preview`: ビューポート上での形状表示/非表示（顔のアイコン）を切り替える。
      - `Bake`: Grasshopper定義のRhinoモデル化（目玉焼アイコン）。
    - 端子（パラメーター）の右クリック: 入出力端子（X, Y, Zなど）を個別に右クリックすることで、そのパラメーター名を変更できる。
5. **一部コンポーネントのダブルクリック:** 一部のコンポーネントをダブルクリックするとエディタや設定画面が開く
    - Panel（パネル）: テキストの編集画面
    - Number Slider（数値スライダー）: スライダーの設定画面（小数点以下の桁数、最小値・最大値など）
    - Python: スクリプトエディタ
6. **コンポーネントの削除:**
    - 不要なコンポーネントは、対象を選択して `Delete` キーを押すことで削除できる。

    <div class="media-wrapper">
        <video src="/docs/images/lab/intro_to_cd/loft.mp4"
        autoplay
        muted
        loop
        playsinline></video>
    </div>

7. **Grasshopper定義のRhinoモデル化: `Bake`**  
  Grasshopperのキャンバス上で構築されているジオメトリは、Rhinoのビューポート上に見かけの形状を「プレビュー（赤色や緑色で表示）」しているだけです。そのため、Grasshopperを閉じると形状は消え、Rhino側で選択したり、そのまま他のCADへ書き出したりすることはできません。
  - **`Bake`（ベイク）とは:** Grasshopperのデータを、Rhinoの「実データ」として空間に「**焼き付ける**（出力する）」操作です。コンポーネントを右クリックして Bake を実行すると、Rhinoの通常のオブジェクトとして確定されます。
  - **トレードオフ:** BakeしたジオメトリはRhinoの通常のモデリングデータとなるため、Grasshopper側のパラメーターとは切り離され、連動しなくなります。 

### 2.3 データ構造

Grasshopperでは、データの流れを単なる1列ではなく、枝分かれした構造で扱います。これを「**データツリー**」と呼びます。データツリーは、**寿司（データ）**と**お皿（データの階層）**の関係性で考えるとわかりやすいです。

- **データツリーとは:** 寿司（点や数値などのデータ）を整理するための「お皿の集まり」です。
  - **List（リスト）:** 1枚の長いお皿に、複数の寿司が順番に並んでいる状態です。
  - **Data Tree（データツリー）:** テーブルの上に複数のお皿が並び、寿司が小分けされている状態です。

  ![](/docs/images/lab/intro_to_cd/data_tree.jpg)

  ```
  【普通のリスト】
    🍽️ お皿 ─── [ 🍣(0), 🍣(1), 🍣(2), 🍣(3) ] （1枚に全部載っている）

  【データツリー】
    📁 皿{0} ── [ 🍣(0), 🍣(1) ]
    📁 皿{1} ── [ 🍣(0), 🍣(1) ] （お皿が分かれている）
  ```

- **ルール:** Grasshopperのコンポーネントで2つのデータを組み合わせて処理する場合、「**同じお皿の、同じ番号のもの同士（ネタとシャリ）**」を順番に組み合わせ握ります。

  ```
  【ネタ】                        【シャリ】                            【完成】
  📁 皿{0} ── [ 🐟(0), 🦑(1) ]   📁 皿{0} ── [ 🍚(0), 🍚(1) ]  ──>  📁 皿{0} ── [ 🍣(0), 🍣(1) ]
  📁 皿{1} ── [ 🦐(0), 🐙(1) ]   📁 皿{1} ── [ 🍚(0), 🍚(1) ]  ──>  📁 皿{1} ── [ 🍣(0), 🍣(1) ]
  ```

- **ありがちな失敗:** 構造がずれると、意図しない結果になります。
  - 1つの皿に大量のデータが集まり、1点に線が集中してしまう。
  - 片方のデータ数が少ない場合、最後の要素が繰り返し使われてしまう（Grasshopperの仕様）。
  - お皿の階層がずれて、データが見つからず消えてしまう。

- **よく使う操作:**
  - **Flatten:** 複数のお皿にのった寿司を1つの長い皿にまとめる。
  - **Graft:** 1つのお皿に入っていた寿司を、一つずつ別々のお皿に分ける。
  - **Simplify:** 余分に重なっているお皿を単純化する（例: お皿が2枚重なっているものを、1枚にする）。
  - **List Item:** お皿の上に並んでいる寿司の中から、指定した順番（インデックス）のものをつまんで取り出す。
  - **Merge:** 別々の場所から流れてきた複数のデータを、お皿の番号に従って、1つの流れに合流させる。

- **実際のGhの例**
  - **Listの例（上段）:** `Construct Point`のX座標にList (0, 10, ... 40) を入れ、5個のポイントを作成。
  - **Data treeの例（下段）:** `Construct Point`のX座標に、`Graft`したList（一つずつ小皿に分けた状態）を入れ、Y座標には通常のListを入れることでグリッドを作成。X(0) に対しY(0, 1, ... 4)と処理され、 X(1) に対しY(0, ... 4)…と処理が続けられる。
  ![](/docs/images/lab/intro_to_cd/data.jpg)

> **Find Component:** コンポーネントを **`Ctrl + Alt`** を押しながらクリックすると、そのコンポーネントが上部タブのどこにあるかを赤い矢印で視覚的に教えてくれます。

> **Grasshopper参考:**
- [Grasshopper コンポーネントIndex (AppliCraft)](https://www.applicraft.com/ghcp_index/)
- [Computational Design for (Industrial) Designers using Rhino Grasshopper (Delft University of Technology)](https://interactivetextbooks.tudelft.nl/rhino-grasshopper/Grasshopper_Rhino_course/intro.html)

> **AIを使った学習:**
- Grasshopperはドキュメントが豊富でコミュニティも活発なため、多くの場合AIに質問することで適切な回答を得ることができます。また、Grasshopper定義を通常の`.gh`ではなく`.ghx`形式（XMLベースのプレーンテキスト）で保存すると、AIが解析できるようになります。

---
## 3. Script入門

### 3.1 環境の起動と初期設定

ScriptはRhino上でもGrasshopper上でも使えます。Rhinoでは主に自動化処理、Grasshopperではパラメーターに応じた編集や、コンポーネントの補助に使用します。

1. **Rhino上で使う**
    1. Rhinoのメニューバーから **[ツール] ──> [スクリプト] ──> [編集]** を選択して、スクリプトエディタを起動する。
    2. エディタにコードを入力する、既存のスクリプトを開く、またはコピーしたコードを貼り付ける。
    3. 実行すると、Rhino上の点・線・曲線などを直接生成・編集できる。
    4. 生成したスクリプトは `.py` ファイルとして保存しておくと、後で再利用しやすい。

1. **Grasshopper上で使う**
    1. Grasshopperを起動し、キャンバス上に `Python` コンポーネントを配置する。
    2. コンポーネントをダブルクリックして、Pythonエディタを開く。
    3. コンポーネントの入力端子からデータを受け取り、処理結果を出力する。
    4. スクリプト内の変数名は、コンポーネントの入力・出力名と合わせる。

### 3.2 主要ライブラリ

PythonからRhinoの機能を使用するために、コードの最上部で各種ライブラリを呼び出します。ライブラリとは、あらかじめ用意された機能の集まりで、例えば「点を作る」「線を引く」「距離を測る」といった操作を簡単に実行できるようにしたものです。

- **Rhino用のライブラリ:**
    - `rhinoscriptsyntax`: Rhinoの主要なコマンドを簡潔に記述できる簡易コマンド集（ラッパー）。多くの場合、これだけで十分です。
    - `Rhino`: より高度な制御を可能にするコアAPI（RhinoCommon）。
- **その他の一般的なライブラリ:**
    - `math`: Python標準ライブラリの一つで、数値計算に使われます。
    - `random`: 乱数を扱うためのPython標準ライブラリです。
    - `os`: ファイルやフォルダの操作に使われる、一般的なPython標準ライブラリです。
- **呼び出し例（`rhinoscriptsyntax`を使用する場合）**
  - スクリプトの冒頭に、`import rhinoscriptsyntax as rs` と書く
  - 以後は `rs` という短い名前で使える（例: `rs.AddPoint(x, 0, 0)`）
  - **Rhinoの公式ドキュメント（[RhinoScriptSyntax](https://developer.rhino3d.com/api/RhinoScriptSyntax/)）**で利用できるコマンド（`rs.AddPoint()`）や関数（`()`の中身）を確認できます。

### 3.3 基本構文

- **Pythonの基本規則**
  - **インデント（字下げ）:** Pythonでは、コードのブロック構造をインデント（半角スペース4つ、またはTabキー1回）で定義します。インデントのズレや全角スペースの混入は構文エラーとなります。
  - **コメントの記述:** コードの処理内容とは別に、各ステップの意図や補足を説明するコメントを追加できます。Pythonでは`#`の後にコメントを記入します（例: `# Create points in a straight line`）

    - **注意:** Rhino Pythonでは、コメントには全角日本語を入れると文字コードのエラーになる場合があるため、半角英語（`# English code comment`）で記述するようにします。
- **forループ**
  
  Pythonでは、`for` 文を使うと同じ処理を繰り返し実行できます。たとえば `for i in range(10):` と書くと、`i` に0から9までの値を順番に代入し、10回処理を実行します。

  ```py
  import rhinoscriptsyntax as rs     # Rhino script library (alias rs)

  for i in range(10):
      x = i * 2.0
      rs.AddPoint(x, 0, 0)
  ```

  - 同じ作業を繰り返す場合に、スクリプトのループが特に大きな強みになります。手動操作やGrasshopperでは1つずつ扱う必要がある処理でも、スクリプトではループを使って一括で処理できます。
    - **注意点:** ループ内部の処理によっては実行時間が膨大になるため、`range`は小さな値から始めるようにします。

- **if文**

  `if` 文を使うと、条件が成り立つときだけ処理を実行できます。たとえば「値がある程度大きいときだけ点を作る」といった分岐を記述できます。

  ```py
  import rhinoscriptsyntax as rs

  value = 5
  if value > 3:
      rs.AddPoint(0, 0, 0)
  ```

  - 条件分岐を使うと、同じコードでも入力や状況に応じて動作を変えられます。

> **補足: Rhinoスクリプト環境の全体像とアーキテクチャ**
>
- **ライブラリ**
    - **[RhinoScriptSyntax](https://developer.rhino3d.com/guides/rhinopython/python-rhinoscriptsyntax-introduction/):** Rhinoのよく使う操作を、Pythonから簡単に呼び出せるようにした命令集（***ラッパー***）です。初心者にとって最も扱いやすく、まずはこれを覚えると理解しやすいです。
    - **[RhinoCommon](https://developer.rhino3d.com/guides/rhinocommon/):** Rhinoのより本格的な機能を直接扱うための***公式API*** / クロスプラットフォーム対応 ***.NET プラグイン SDK（ソフトウェア開発キット）***です。やや難しく、主に開発者向けのレベルです。
- **用語**
    - **API:** ソフトウェア同士がやり取りするための「窓口」のようなものです。Rhinoの機能を外部から呼び出すときに使います。
    - **ライブラリ:** すでに用意された機能の集まりです。Pythonでは `import` して使います。
    - **ラッパー:** 低レベルな機能を、より簡単に使えるように包んだものです。RhinoScriptSyntaxは、RhinoCommonを使いやすくしたラッパーの一例です。
    - `.NETプラグインSDK:` プログラミング言語とは別に、RhinoやGrasshopperの機能を拡張するための開発基盤です。PythonやC#を使う際の土台として理解すると分かりやすいです。
- **利用可能な言語と動作フロー**
    - `Python`: 記述の容易さとAIとの親和性から現在の主流環境です。Rhino 8以降では Python 3 を使うことが前提です。
    - `C#`: 開発者向けの言語で、より高度な制御やプラグイン開発に向いています。
    - `VBScript`: 旧世代の環境で、現在は新規利用は非推奨です。

---
## 4. 比較まとめ（手動・Gh・スクリプト）

Rhinoにおける各アプローチの特性、メリット、およびリスクの比較です。

- **手動操作 (Manual)**
  - **概要:** マウスやCLI（コマンド入力）による個別配置。
  - **メリット:** 直感的。事前のロジック構築が不要で、単発の作業において最速。
  - **デメリット・リスク:** 反復作業や大量データ処理、バリエーション変更に膨大な手作業の工数がかかる。
  - **AIとの親和性:** 非常に低い。

- **Grasshopper (Gh)**
  - **概要:** コンポーネントを視覚的に接続するビジュアルプログラミング。
  - **メリット:** データの流れを視覚的に把握でき、パラメータ変更による形状変化をリアルタイムに検証可能。
  - **デメリット・リスク:** 処理が複雑化するとアルゴリズムが肥大化し、「スパゲッティコード」としてブラックボックス化しやすい。
  - **AIとの親和性:** 低い（グラフ構造の生成はLLMが苦手とする領域）。

- **スクリプト (Script)**
  - **概要:** PythonやC#などのテキストコードによる論理記述。
  - **メリット:** 複雑なループ処理や大量のデータを、極めて省スペースかつ高速に実行できる。
  - **デメリット・リスク:** 固有のプログラミング構文を習得する必要がある。
  - **AIとの親和性:** **極めて高い**（LLMが最も得意とするコードテキスト生成と合致）。

> **工場の自動化への比喩**
> 
> 
> 各手法の役割は工場のフェーズに類似しています。手動操作は「職人による手作り」、Grasshopperは可変性の高い「町工場の生産ライン」、スクリプトは高速大量生産を行う「全自動の無人工場」です。タスクの規模と特性に応じた使い分けが求められます。
> 

> **The 5-Step Algorithm（Elon Musk氏による自動化の基本原則）**
> 
> 
> 効率化を行う際は、以下の手順で自動化は最後に行い、「自動化する必要がないことを自動化する」状況を防ぎます。
> 
> 1. **要件を疑え (Make your requirements less dumb):** その仕様や前提自体が不必要ではないか検証する。
> 2. **プロセスを削除せよ (Delete the part or process):** 不要な工程そのものを破棄する。
> 3. **単純化・最適化せよ (Simplify or optimize):** 削除できない工程を可能な限りシンプルにする。
> 4. **サイクルタイムを加速させよ (Accelerate cycle time):** 処理全体の速度を上げる。
> 5. **自動化せよ (Automate):** 上記のステップをすべて経た後に、最終手段として自動化を実行する。

---
## 5. Grasshopper応用

### 5.1 グリッド配置とアトラクター変形

Grasshopperを用いた数理的形状制御の代表的なプロセスです。

1. **ベースグリッドの生成:** `Series` コンポーネントを用いて等差数列（連番データ）を作成し、`Construct Point` の X座標および Y座標に入力することで、規則的な点群を配置します。
2. **距離の測定:** Rhino空間上に定義した任意の基準点（アトラクター）と、グリッド上の各点との間の距離を `Distance` コンポーネントで一括算出します。
3. **形状へのマッピング:** 算出された距離の数値を各点の Z座標、あるいは各点に配置した幾何形状のスケール値にマッピングします。これにより、基準点の位置に応じてリアルタイムに変形する立体グラデーションが構築されます。

> **拡張プラグイン集: [Food4Rhino](https://www.food4rhino.com/en)**
> 
> Grasshopperには、様々な機能を拡張するプラグインがあり、Food4Rhino で多くのツールを探すことができます。用途に応じて既存のプラグインを導入すれば、解析、生成、インタラクション、製造支援など、幅広いワークフローに対応できます。

---
## 6. スクリプト応用・バイブコーディング

### 6.1 バイブコーディング

- **コードの暗記からの脱却:** 細かい構文の記述は生成AIに任せ、人間は「どのような手順でデータを取得し、どう処理してCADに返すか」というアルゴリズムの構造設計に注力します。
- **プロンプトのコツ:** ハルシネーション（存在しない関数の捏造など）を防止するため、AIへの指示文には以下を指定します。
    - 使用環境の明示（例: 「Rhino 8 / Python 3環境」）
    - 使用ライブラリの制限（例: 「`rhinoscriptsyntax` を使用」）
    - コード内のコメント指示（例: 「デバッグおよびエラー防止のため、1行ごとに半角英語でコメントを入れてください」）
- **デバッグの手順:** スクリプトが正常に動作しない場合は、エディタや出力ウィンドウに表示されたエラーメッセージをそのままAIに共有し、修正案を取得します。

### 6.2 フラクタルツリー（再帰関数と乱数）の生成例

再帰アルゴリズム（関数が自身を繰り返し呼び出す処理）と乱数を組み合わせ、Grasshopper上でPythonを使って複雑な樹形構造を自動生成する例です。

**Grasshopper上での使い方:** 
- Pythonコンポーネントを置き、**変数名**と**データ型**をコードと合わせる（右クリック）。

  | 区分 | 変数名 | データ型 | 役割・説明 |
  | --- | --- | --- | --- |
  | **Input**（左側） | `gen` | Integer (整数) | 成長をストップさせる最大の世代数（**指数関数的に処理が重くなるため、0 ~ 10程度にする**）。 |
  |  | `angle` | Float (実数) | 枝が分岐する際の見開き角度。 |
  |  | `scale` | Float (実数) | 次の世代の枝がどれくらい短くなるかを表す縮小比率（例: `0.8`）。 |
  |  | `seed` | Integer (整数) | ランダムな枝のブレ（揺らぎ）を一意に決定するためのシード値。 |
  | **Output**（右側） | `Lines` | 幾何データ (Line) | 生成されたすべての枝（ラインデータ）のリスト。Grasshopper側へ最終的な形状を出力する変数。 |

- Pythonコンポーネントを開き、スクリプトを貼り付ける。
- Inputに`Number Slider`、アウトプットに`Line`を接続しパラメーター調整。

**仕組み:**
1. **ベクトルの加算と作図**：原点から真上にベクトルを伸ばして基準となる最初の「幹」を描く。
2. **幾何学計算とランダムな回転**：幹の先端から、外側へ扇状に広がる回転軸を計算し、左右に少しランダムなブレを加えた「2本の枝」を作る。
3. **条件付きの再帰処理**：新しくできた枝の先端を次の基準点として同じ分岐処理を繰り返すが、指定した世代数に達したら無限ループを防ぐために処理を終了する。

```py
import rhinoscriptsyntax as rs
import random

# --- 1. Initial Setup ---
A = [0, 0, 0]  # Base point of the tree
V = [0, 0, 1]  # Initial growth direction (straight up)

Lines = []     # List to store all created branch lines

B = rs.PointAdd(A, V)          # End point of the first main trunk
Lines.append(rs.AddLine(A, B)) # Draw the first main trunk

# --- 2. Define the Branch Growth Function ---
def Grow(pt, v, s, a, g):
    # Stop growing if the current generation reaches the limit
    if g >= gen:
        return
        
    # Make the next branch shorter
    v = rs.VectorScale(v, s)
    
    # Calculate the rotation axis to spread branches outward
    plane = rs.PlaneFromNormal(pt, v)
    circle = rs.AddCircle(plane, 0.1)
    t = rs.CurveClosestPoint(circle, A)
    closest_pt = rs.EvaluateCurve(circle, t)
    rot_axis = rs.VectorCreate(pt, closest_pt)

    # Calculate direction for the left branch (with small random variation)
    V1 = rs.VectorRotate(v, -a + random.uniform(-3, 3), rot_axis)
    pt1 = rs.PointAdd(pt, V1)
    
    # Calculate direction for the right branch (with small random variation)
    V2 = rs.VectorRotate(v, a + random.uniform(-3, 3), rot_axis)
    pt2 = rs.PointAdd(pt, V2)

    # Create new lines for the branches
    L1 = rs.AddLine(pt, pt1)
    L2 = rs.AddLine(pt, pt2)

    # Add the new lines to the list
    Lines.append(L1)
    Lines.append(L2)

    # [Recursion] Repeat the growth from the new branch tips (generation + 1)
    Grow(pt1, V1, s, a, g + 1)
    Grow(pt2, V2, s, a, g + 1)

# --- 3. Run the Process ---
random.seed(seed)
# Start growing from the trunk tip (B), starting at generation 0
Grow(B, V, scale, angle, 0)
```

### 6.3 実務効率化：Creoレイヤー階層簡略化スクリプト

外部CADからインポートした深いレイヤー階層をワンクリックでクリーンアップする実務特化型のコードです。大規模データ処理時にRhinoがフリーズするのを防ぐため、描画停止・再開処理を組み込んでいます。

```py
import rhinoscriptsyntax as rs

def SimplifyLayers():
    # 1. Get current layer as root location
    root_layer = rs.CurrentLayer()
    if not root_layer:
        return

    # 2. Stop viewport redraw to handle large assemblies quickly
    rs.EnableRedraw(False)

    # 3. Get all sublayers under the root layer
    sub_layers = rs.LayerChildren(root_layer)
    if not sub_layers:
        rs.EnableRedraw(True)
        return

    for layer in sub_layers:
        objects = rs.ObjectsByLayer(layer)
        if objects:
            # Move objects directly to the second-tier parent layer
            rs.ObjectLayer(objects, root_layer)

        # Delete empty sublayer safely
        if not rs.ObjectsByLayer(layer):
            rs.DeleteLayer(layer)

    # 4. Resume redraw
    rs.EnableRedraw(True)

SimplifyLayers()
```

### 6.4 スクリプトのコマンドボタン化手順

作成したスクリプトを、エディタを経由せずにRhinoのUIから直接実行するための登録手順です。

1. **スクリプトファイルの保存:**  
作成したコードを `.py` 拡張子で以下のフォルダへ保存します。  
`C:\Users\[ユーザー名]\AppData\Roaming\McNeel\Rhinoceros\8.0\scripts`
2. **絶対パスの取得:**  
保存した `.py` ファイルを右クリックし、**「パスのコピー」** を選択してフルパスを取得します。
3. **UIボタンの追加:**  
Rhinoツールバー上の空白部分で右クリックし、**「新規ツールバーボタン」** を選択して空のボタンを作成します。
4. **実行マクロの設定:**
コマンド欄に以下のマクロを記述します。
`_-RunPythonScript "コピーした絶対パス"`  
（例: `_-RunPythonScript "C:\Users\...\scripts\my_script.py"`）

> **マクロ記述の補足**
>
> パス前後のダブルクォーテーション `"` は、フォルダ名にスペースが含まれる際のエラーを防ぐために必須です。頭の `_-`（アンダーバーとハイフン）は、実行時のファイル選択ダイアログのポップアップを抑制し、クリックと同時にバックグラウンドで処理を即時実行させるための標準的な構文ルールです。
> 

---
## 7. MCP動向

### 7.1 概要

生成AIを活用したデザインは、従来の「AIがアイデアを生成していても、最終的には人間がCADで手動操作して実行する」スタイルから、**MCP（Model Context Protocol）** を介して「AIエージェントがCAD環境のAPIを直接たたき、形状の作成・検証・修正までを自律的に行う」ワークフローへとシフトしています。

MCPとは、LLM（大規模言語モデル）と、外部のアプリケーションやデータソースとの間を安全かつ標準化された作法で接続するユニバーサル・アダプター（オープン規格）です。これに対応することで、AIはCAD環境内のコンテキストを読み取り、自律的に適切な操作ツールを選択して実行できるようになります。

### 7.2 主要CAD/BIMツールにおける最新動向

- **Autodesk Fusion MCP:** AutodeskはAnthropicと協働し[Fusion MCP](https://aps.autodesk.com/blog/bringing-fusion-claude-creative-work)を導入しました。ユーザーの自然言語による「ブラケットの肉厚の変更」や「ボルト穴の移動」といった指示に対し、AIがFusionのAPIを直接実行してモデリング変更やデータ書き出しまでを自動完結させます。実務ではモデリング自動化用の拡張機能（Add-in）を開発する「ペアプログラミング」用途で特に高く評価されています。
- **Rhino MCP:** コンピュテーショナルデザイン領域においても、コミュニティ主導のMCPプラグインが急速に浸透しているのに加え、McNeel公式のGitHubでもプラットフォームの構築が進められています。
  - **[Rhino MCP Platform](https://mcneel.github.io/RhinoMCP/):** McNeelはGitHub上にて公式プロジェクト `mcneel/RhinoMCP`（パッケージマネージャー名：`RhinoMcpPlatform`）を公開し、急ピッチでコア開発を進めています。バージョン0.1.x以降ではレイヤー操作やスクリプト実行を含む多くのツールが解放され、会話を通じたモデリングの自動化が進んでいます。
  - **[Raven](https://www.raven.build/en):** Grasshopperのアルゴリズム（グラフ構造）自体をAIに自律的に構築・配線・パラメータ調整させるプラグイン。初心者にとっての壁である複雑なデータツリー（リスト階層）の処理も、AIが自動でリワイヤするため高く評価されています。
- **Blender MCP:** メディア・エンターテインメント領域でもコミュニティ主導で `Blender MCP` アドオンの開発が爆発的に進んでいます。Blenderは内部操作のほぼ全てがPython APIで記述できるため相性が抜群に良く、抽象的な自然言語の指示から、AIがオブジェクト配置・マテリアル・ライティング設定までを自律実行するアドオンがクリエイターの間で実用化されています。

### 7.3 Rhino MCP のシステム構成・通信フロー

AIクライアントからRhinoが操作される内部処理は、以下の3レイヤーの構造で成立しています。

```
[ AIクライアント ] (Claude Desktop / Cursor / Claude Code など)
       │
       │ （標準規格: stdio / JSON-RPC 通信）
       ▼
[ MCPサーバー ] (Python / FastMCP などのローカルミドルウェア)
       │
       │ （ローカル通信: TCP Loopback / Socket / 127.0.0.1:10501）
       ▼
[ Rhinoプラグイン ] (C# RhinoCommon / Python 常駐リスナー)
       │
       ▼ 【Rhino / Grasshopper 内部での動的コード実行・ジオメトリ操作】

```

1. **AIクライアント:** ユーザーの指示を受け取り、MCPサーバーから開示されている「利用可能なツール仕様（JSON Schema）」に基づいて、最適なコマンドとパラメータを内包した要求を発行します。
2. **MCPサーバー:** AIとCAD実機の中間に常駐する軽量なローカルプログラムです。AIからの操作要求（JSONデータ）を、CAD側が解釈可能な通信プロトコルに翻訳して中継します。
3. **Rhinoプラグイン:** Rhinoの内部でコマンド（`MCPConnect` など）を実行することで起動するサーバーです。中継された命令を受け取り、Rhinoのメインスレッド上でネイティブコマンドやPython/C#のコードをその場で動的実行し、3D空間への形状反映と実行結果のフィードバックを行います。

### 7.4 インプリケーションと今後の課題

**現時点の課題（ユーザーフィードバックに基づく制限）:**
- **厳密な空間認識能力の不足:** 現状のLLMは2D画像やテキストの理解には優れているものの、3D空間のトポロジー（位相関係）や厳密な座標、定性的な「美観」の直感的な理解がまだ発展途上であるため、抽象的な指示では形状が破綻しやすい。
- **コンテキスト制限（オブジェクト数の壁）:** 大規模アセンブリや複雑なシーンでは、3Dデータ全体の情報をAIに渡すとトークン上限を超えて破綻する。オープンソースの初期実装などでは「1回に取得できるオブジェクトやレイヤー数を最大30個に制限する」といった暫定処置が取られており、大規模実務への適用にはまだ壁がある。
- **パフォーマンスの最適化不足:** 例えばFusionにおいて「パターン配置」や「大規模な肉厚変更」を指示した際、AIはAPIを愚直に実行するため処理が極端に重くなる。人間が明示的に `deferred compute（遅延計算）` などの最適化ロジックをプロンプトで指示しない限り、フリーズ寸前まで重いコードを生成してしまう傾向がある。

**安全性の担保と新たな技術負債:**
- **エントロピーの罠（ロジックのブラックボックス化）:** Grasshopperにおいて、効率化のためにAIにC#やPythonコードを書かせて1つのカスタムノードにまとめさせる手法が流行しているが、これはGrasshopper本来の強みである「データがワイヤーを通る視覚的フィードバック」を失わせる。中身がAIの書いた難解なコードだらけになり、人間が後から手動でリワイヤ（配線修正）できなくなる新たな技術負債が懸念されている。
- **自律実行による不具合:** AIエージェントに自律的なモデリング変更を許可する場合、意図しないスケッチ拘束の破壊や、製造不可能な自己交差形状の生成リスクがある。そのため、実務運用においては「AIの自律境界線」の設定、および接続インフラ（stdio接続方式のアップデート追従など）の安定性確保が議論されている。

**インプリケーション:**
- CAD操作習得のラーニングカーブがなだらかになり、これまで最大のボトルネックだった「大量のコンポーネント暗記」や「複雑なAPIリファレンスの検索」をショートカットできるようになる。
- デザイナーの仕事は手を動かしてモデリングすることから、モデリングはMCPに任せ、より上位レイヤーの「制約条件の定義」や「バリエーションのディレクション」にシフトする。
- 設計プロセスのループが高速になり、CAE（強度解析）ツール等と連携した「AIが形状生成 → 解析 → 自動修正」という自律的な最適化ループの構築が現実味を帯びている。
--->