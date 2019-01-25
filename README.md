cygwin_smile
============

# Cygwinでdllに依存しないexeの作り方

### 準備
Cygwin Setupで「mingw64-x86_64-gcc-core」 をインストール

### アイコンファイルの作成
```
wget magna.ico
vi magna.rc
MAGNA_ICON ICON magna.ico
```

### コンパイル
```
windres.exe -i icon.rc icon.o
x86_64-w64-mingw32-gcc -mwindows -o magna magna.c icon.o
```

### 参考
 [Cygwinでdllに依存しないexeの作り方](http://d.hatena.ne.jp/wlt/20111231/1325289060)
 
 [アイコンの作成法](http://www.cs.hiroshima-u.ac.jp/~yasuaki/dokuwiki/cygwin)
