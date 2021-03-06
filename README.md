# デバッグ演習1: Number Counter


## プログラムの仕様
- 第1引数で指定したファイルを開き、データを読み込みます。
  - ファイルには0〜255までの数字が1行に1つずつ書かれています。
  - ファイル内には最大で512個の数字が書いてあります。
- 第2引数以降の引数で指定された0〜255までの数字群が、ファイルの中でそれぞれ何回出てくるのかを画面に出力します。
    - 各数字の出現回数を1行に表示します。
  - 引数で指定できる数字は最大で16個とします。

### 例
- ファイル ``test.dat``

    30  
    30  
    180  
    102  
    180  
    180  
    255  
    1

- 実行コマンド

    ./num_count test.dat 30 102 255 0

- 出力

    30 2  
    102 1  
    255 1  
    0 0


## 課題
- commitされているプログラムにはバグがあり、上述の動作を果たせません。
- 以下の手順で修正して下さい。
  1. このrepositoryをforkして下さい。
  1. dubug_note.txtというファイルに以下の点を記載し、commitして下さい。
     - 可能な限りバグを見つけ、各バグを再現できる条件とバグの内容、本来期待される動作を記載
     - 各バグの原因を特定し、特定した方法とともに記載
  1. 特定した原因を踏まえて対策を検討し、修正を加えてcommitして下さい。
- Pull Requestして下さい。
