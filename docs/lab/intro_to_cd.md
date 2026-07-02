---
layout: default
---

# Intro to Computational Design

2026 \| Computational design \| Rhino / Grasshopper / Python

Caption_goes_here.

![](/docs/images/lab/IMAGE_GOES_HERE)

## #1 コンピュテーショナルデザイン概要

### 1. 目的
 * **つかってみる:** ハードルを下げる。
 * **プロセスを構築すること:** モデリングするための「ルール（アルゴリズム）」をデザインする。
 * **手作業と自動化のバランス:** 自動化による可能性と、自動化のためのルール構築の工数のバランスの見極め。
 * **AI連携への理解:** MCP（モデルコンテクストプロトコル）などのAI活用への理解。

### 2. 言葉の整理
様々な言葉があるが、文脈により定義は曖昧。
 * **CAD (Computer Aided Design)**
   * コンピューターを使ったデザイン全般。
 * **Computational Design（広義の総称）**
   * 計算能力をデザインプロセスに持ち込む手法全般。
 * **Parametric Design（変数と関係性）**
   * 要素間に「ルール（寸法や位置の関係性）」を構築し、変数（パラメーター）を編集することにフォーカス。
 * **Algorithmic Design / Procedural Design（論理と手順の制御）**
   * 「論理的・数理的な手順（プロセス）」の組み立てにフォーカス。
 * **Generative Design（自律的な探索）**
   * 「ゴール（目標値・制約条件）」だけを設定し、AI/アルゴリズムに最適解を生成させる。

> ### *"Parametric Architecture"*
> 
- 「Grasshopper を使った複雑で有機的な建築」と言うイメージが一般的
- 「日照・風向・構造負荷などのパラメーターを含めた総合的なデザイン」と捉える人もいる
- 建築家パトリック・シューマッハ（ザハ・ハディド・アーキテクツ）は「パラメトリシズム」を21世紀の建築様式として提唱

### 3. Rhino上で使えるツール
同じ形状（例：10個の点を直線状に並べる）を作るアプローチの違い。
 * **手動操作（Manual）**
   * マウス操作やコマンド入力（CLI）で1つずつ配置する。
   * **メリット:** 直感的でプロセスを構築する必要がない。
   * **デメリット:** 繰り返し作業や大量処理、大量のバリエーション作成が苦手（人間が）。
 * **Grasshopper（Visual Programming）**
   * コンポーネント（機能の箱）をワイヤーで繋いで形状を作る。
   * **メリット:** データの流れが視覚的に分かりやすく、リアルタイムに形状を変更できる。
   * **デメリット:** 処理が複雑になるとアルゴリズムが肥大化し、スパゲッティ状態になりやすい。AIとの相性があまり良くない。
 * **スクリプト（Programming）**
   * Pythonなどのテキストコードを記述して処理する。
   * **メリット:** 複雑なループや大量のデータを高速かつ省スペースで記述できる。AIと最も相性が良い。
   * **デメリット:** 構文の習得が必要。

---
### 4. Grasshopperの基本

#### 4.1 基本概念
 * **コンポーネント:** 入力（左側）を受け取り、処理を行い、出力（右側）を返す単位。
 * **ワイヤー:** コンポーネント間でデータを流す経路。
 * **パラメーター:** 数値スライダー（Number Slider）などを使い、リアルタイムに変更可能な変数。

#### 4.2 基本デモ：グリッド状の点配置と変形
 1. **点の生成:** Construct Point コンポーネントを配置。
 2. **連続データの作成:** Series コンポーネントを使い、X座標とY座標に連番を入力してグリッド状に点を配置。
 3. **アトラクターの導入:** 任意の点（アトラクター）を基準に各点との距離（Distance）を測定し、その数値を点のZ座標や半径にマッピングすることで、グラデーションのある立体的な変形を作る。

---
### 5. Rhino Pythonの基礎

#### 5.1 環境の起動と初期設定
 1. メニューバーから **[ツール] ──> [スクリプト] ──> [編集]** を選択してエディタを起動。
 2. **⚠️注意：** 初回起動時は「Python 3ランタイムの初期化」が裏で走るため、数分ほどお待ちください。2回目以降の起動はスムーズになります。

#### 5.2 Pythonの最小限のルール
 * **インデント（字下げ）が命:** スペース4つのズレが即エラーになります。
 * **日本語コメントの禁止:** # コメント に日本語を入れると動かないリスクがあるため、すべて英語で記述します。

#### 5.3 ループのデモ（0から9までの連番）

* ライブラリ（コマンド集）を呼び出し。
  * `import` を先頭に書いて呼び出す（`import rhinoscriptsyntax as rs（略称）`）
    * 実務で使う主要な3つ:
      * `rhinoscriptsyntax`: 多くのRhinoのコマンドを使える。
      * `Rhino`: 
      * `math`: 
  * `rs.コマンド名(変数)`

```python
import rhinoscriptsyntax as rs     # Rhino操作ライブラリ（略称 rs）

# 0から9まで10回繰り返すループ
for i in range(10):
    # ループ変数をX座標に流用して、直線状に10個の点を配置
    x = i * 2.0
    rs.AddPoint(x, 0, 0)

```

#### 5.4 応用デモ：フラクタルツリー（樹形構造）の生成
同じ処理を繰り返す「再帰関数」と、自然界の揺らぎを表現する「ランダム（乱数）」を組み合わせ、手作業では描けない複雑な構造を作ります。

```python
import math
import random
import rhinoscriptsyntax as rs

# Default settings (If not predefined in Grasshopper inputs)
if "scale" not in globals(): scale = 0.75
if "angle" not in globals(): angle = 25.0
if "gen" not in globals(): gen = 6
if "seed" not in globals(): seed = 42

random.seed(seed) # Fix random shapes
Lines = []

A = [0, 0, 0]
V = [0, 0, 5] # Base trunk vector

B = rs.PointAdd(A, V)
Lines.append(rs.AddLine(A, B))

def Grow(pt, v, s, a, g):
    if g >= gen: # Stop condition
        return
        
    v_scaled = rs.VectorScale(v, s)
    plane = rs.PlaneFromNormal(pt, v_scaled)
    circle = rs.AddCircle(plane, 0.1)
    
    t = rs.CurveClosestPoint(circle, pt)
    closest_pt = rs.EvaluateCurve(circle, t)
    rot_axis = rs.VectorCreate(pt, closest_pt)
    rs.DeleteObject(circle)
    
    # Left branch with slight random variation
    v1 = rs.VectorRotate(v_scaled, -a + random.uniform(-3, 3), rot_axis)
    pt1 = rs.PointAdd(pt, v1)
    
    # Right branch
    v2 = rs.VectorRotate(v_scaled, a + random.uniform(-3, 3), rot_axis)
    pt2 = rs.PointAdd(pt, v2)
    
    Lines.append(rs.AddLine(pt, pt1))
    Lines.append(rs.AddLine(pt, pt2))
    
    # Recursive loop
    Grow(pt1, v1, s, a, g + 1)
    Grow(pt2, v2, s, a, g + 1)

# Execute
Grow(B, V, scale, angle, 0)

```

### 6. 手動操作、Grasshopper、スクリプトのまとめ
 * **手動操作:** 手順は自由で先のことを考えないでよいが、自動化できない。
 * **Grasshopper:** 複雑なプロセスを視覚的に構築し、設定した範囲のパラメータを調整できる。構築する手間とパラメーター調整の効果の見極めが必要。AIとの相性はあまり良くない（RavenなどAIプラグインもある）。
 * **スクリプト:** 大量処理・自動化・コマンド構築に向く。AIと相性が良い。

**工場の自動化のようなもの。手動操作は職人の手作り、Grasshopperは町工場、スクリプトは全自動の無人工場。**

> ### *The 5-Step Algorithm*
1. 要件を疑え (Make your requirements less dumb): その要件自体が間違っている可能性があるため、誰が出したものであっても常に疑うこと。
1. プロセスを削除せよ (Delete the part or process): 自動化や最適化に取り組む前に、まずはそのプロセス自体が不要ではないかと考え、削除を試みること。
1.  単純化・最適化せよ (Simplify or optimize): ステップ2で削除できなかった場合のみ、処理をシンプルにすること。
1. サイクルタイムを加速させよ (Accelerate cycle time): プロセスを高速化すること。
　自動化せよ (Automate): 最後に、すべてのプロセスを自動化すること。

---
---
## #2 実務での活用 ＋ ハンズオン

### 1. マインドセット：生成AI時代のバイブスコーディング」
 * **コードは暗記しない:** 細かい構文はAIに書かせれば良い。「どういう手順で、何がどう動いているか」の大まかな仕組み（構造）の理解に集中する。
 * **AI（プロンプト）の鉄則:** 「Rhino8 / Python 3環境」「rhinoscriptsyntax 使用」と環境を必ず指定し、ハルシネーション（嘘の関数）を防ぐために「1行ごとに英語コメント（#）を入れて」と頼む。
 * **バグが出たら:** 「動きません」ではなく、画面に出たエラー文を丸ごとコピペしてAIに投げる。

### 2. 【後半ハンズオン】実務で活きるスクリプト活用例
*(※今後、Grasshopperとスクリプトの具体的な活用事例を追加予定)*

#### 2.1 実務効率化：Creoレイヤー階層簡略化スクリプト
外部CAD（Creoなど）からインポートした深いレイヤー階層を自動整理し、大規模データでも固まらないように描画停止処理を追加した実務特化コード。

```python
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

### 3. 作成したスクリプトをワンクリックのコマンド（ボタン）にする方法

保存したスクリプトを、エディタを開かずにRhinoのUIから直接実行できるように登録する。
 1. **スクリプトの保存:** コードを .py ファイルとして以下の標準フォルダに保存する。
   * C:\Users\[ユーザー名]\AppData\Roaming\McNeel\Rhinoceros\8.0\scripts
 2. **パスのコピー:** 保存した .py ファイルを右クリック ──> **「パスのコピー」**。
 3. **ボタンの新規作成:** Rhinoのツールバーの空きスペースで右クリック ──> **「新規ツールバーボタン」**。
 4. **マクロ（コマンド）の設定:** 新規ボタンを Shift ＋ 右クリックで開き、以下を入力。
   * **名前 / 画像:** 任意。
   * **コマンド:** _-RunPythonScript "コピーしたパス" を貼り付ける。
   * *(例: _-RunPythonScript "C:\Users\...\scripts\my_script.py"。前後の " を忘れないこと。頭の _- がダイアログのポップアップを抑制し、即実行させます。)*

> ### *Rhinoスクリプト環境の全体像*
1. スクリプトで使用するライブラリ（`import ~ as ...`）
  * **RhinoCommon:** Rhinoを動かすための公式API (*)。C#だけでなくPythonからも直接操作可能。高機能だが記述量が多いため、できれば使いたくない。
    * **RhinoScriptSyntax:** 記述量の多いRhinoCommonを、Pythonで簡単に扱えるようにした簡易コマンド集（ラッパー）。裏ではRhinoCommonが動いている。
1. Rhinoで使用できるプログラミング言語
  - **VBScript:** 旧方式のため使用する必要はない。互換性維持のため。`ツール → Rhino Script` で間違って使わないよう注意。
  - **Python:** 使いやすいため主流。`(RhinoScriptSyntax) → RhinoCommon → Rhino本体`
  - **C#:** 開発者向け。`(RhinoScriptSyntax) → RhinoCommon → Rhino本体`
>
> **.NETプラグインSDK**: Rhino/Grasshopperプラグインを開発しやすいよう整備されたソフトウェア開発キット。これらがRhino公式で整備されているため、各種Rhinoプラグインや、AI MCPの開発が活発。
