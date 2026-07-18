---
layout: default
---

# Intro to Computational Design

2026 \| Computational design \| Rhino / Grasshopper / Python

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

    <div class="media-wrapper">
      <video src="/docs/images/lab/intro_to_cd/basics.mp4"
      autoplay
      muted
      loop
      playsinline></video>
    </div>
    
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

  <!---
  ```
  【普通のリスト】
    🍽️ お皿 ─── [ 🍣(0), 🍣(1), 🍣(2), 🍣(3) ] （1枚に全部載っている）

  【データツリー】
    📁 皿{0} ── [ 🍣(0), 🍣(1) ]
    📁 皿{1} ── [ 🍣(0), 🍣(1) ] （お皿が分かれている）
  ```
  --->

- **ルール:** Grasshopperのコンポーネントで2つのデータを組み合わせて処理する場合、「**同じお皿の、同じ番号のもの同士（ネタとシャリ）**」を順番に組み合わせ握ります。

  ![](/docs/images/lab/intro_to_cd/merge.jpg)

  <!---
  ```
  【ネタ】                        【シャリ】                            【完成】
  📁 皿{0} ── [ 🐟(0), 🦑(1) ]   📁 皿{0} ── [ 🍚(0), 🍚(1) ]  ──>  📁 皿{0} ── [ 🍣(0), 🍣(1) ]
  📁 皿{1} ── [ 🦐(0), 🐙(1) ]   📁 皿{1} ── [ 🍚(0), 🍚(1) ]  ──>  📁 皿{1} ── [ 🍣(0), 🍣(1) ]
  ```
  --->

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

  ![](/docs/images/lab/intro_to_cd/graft_flatten.jpg)

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

- **Autodesk Fusion MCP:** AutodeskはAnthropicと協働し[Fusion MCP](https://aps.autodesk.com/blog/bringing-fusion-claude-creative-work)を導入しました。ユーザーの自然言語による「ブラケットの肉厚の変更」や「ボルト穴の移動」といった指示に対し、AIがFusionのAPIを直接実行してモデリング変更やデータ書き出しまでを自動完結させます。
- **Rhino MCP:** コンピュテーショナルデザイン領域においても、コミュニティ主導のMCPプラグインが急速に浸透しているのに加え、McNeel公式のGitHubでもプラットフォームの構築が勧められています。
  - **[Rhino MCP Platform](https://mcneel.github.io/RhinoMCP/):** McNeelはGitHub上にて公式プロジェクト `mcneel/RhinoMCP`（パッケージマネージャー名：`RhinoMcpPlatform`）を公開し、急ピッチでコア開発を進めています。
  - **[Raven](https://www.raven.build/en):** Grasshopperのアルゴリズム（グラフ構造）自体をAIに自律的に構築・配線・パラメータ調整させる。

### 7.3 Rhino MCP のシステム構成・通信フロー

AIクライアントからRhinoが操作される内部処理は、以下の3レイヤーの構造で成立しています。

```
[ AIクライアント ] (Claude Desktop / Cursor など)
       │
       │ （標準規格: stdio / JSON-RPC 通信）
       ▼
[ MCPサーバー ] (Python / FastMCP などのローカルミドルウェア)
       │
       │ （ローカル通信: TCP Loopback / Socket / 127.0.0.1:1999）
       ▼
[ Rhinoプラグイン ] (C# RhinoCommon / Python 常駐リスナー)
       │
       ▼ 【Rhino / Grasshopper 内部での動的コード実行・ジオメトリ操作】
```

1. **AIクライアント:** ユーザーの指示を受け取り、MCPサーバーから開示されている「利用可能なツール仕様（JSON Schema）」に基づいて、最適なコマンドとパラメータを内包した要求を発行します。
2. **MCPサーバー:** AIとCAD実機の中間に常駐する軽量なローカルプログラムです。AIからの操作要求（JSONデータ）を、CAD側が解釈可能な通信プロトコルに翻訳して中継します。
3. **Rhinoプラグイン:** Rhinoの内部でコマンド（`mcpstart` など）を実行することで起動するソケットサーバーです。中継された命令を受け取り、Rhinoのメインスレッド上でネイティブコマンドやPython/C#のコードをその場で動的実行（エボリューション）し、3D空間への形状反映と、その実行結果のエラーフィードバックを行います。

### 7.4 インプリケーションと今後の課題

- **インプリケーション:**
  - CAD操作習得のラーニングカーブがなだらかになる、または習得が必要なくなる。
  - デザイナーの仕事は手を動かしてモデリングすることから、モデリングはMCPに任せ、より上位レイヤーの指示にシフトする。
  - これまでCAD操作でボトルネックだった「最終的なモデリング」がAIによる実行対象として扱われることで、設計プロセスのループが高速になり、検討時間の短縮や検討の幅を広げることに繋がる可能性がある。
- **現時点の課題:**
  - 3Dデザインは、自然言語や画像に比べて学習データの量と品質がまだ十分ではない可能性がある。
  - 構造・製造可能性・美観の相互作用のバランスを理解するためには、それぞれの要素を数値化し、設計上の重みづけを行うことが必要になる可能性がある。
  - そのため、AIが3D設計を安定して実務レベルで扱えるようになるには、もう少し時間がかかる可能性がある。
- **安全性の担保:** 
  - AIに処理を任せることで設計ロジックがブラックボックス化する恐れがある。
  - 自律的なAI実行による予期しない不具合のリスクがある。実務運用においては、セキュリティ境界線の定義が議論されている。
