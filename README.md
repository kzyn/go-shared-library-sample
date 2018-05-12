# go-shared-library-sample

## Linuxビルド手順
### so作成
go build -buildmode=c-shared -o lib.so lib.go
→lib.hが作成される

### 実行ファイル作成
gcc lib.so main_linux.c


### 備考
環変数LD_LIBRARY_PATHの追加が必要


## Windowsビルド手順
### アーカイブ作成
go build -buildmode=c-archive -o lib.a lib.go
→lib.hが作成される

### dll作成
gcc -m64 -shared -o lib.dll lib.def lib.a  -Wl,--allow-multiple-definition -static -lstdc++ -lwinmm -lntdll -lWs2_32

### 実行ファイル作成
gcc main_windows.c

