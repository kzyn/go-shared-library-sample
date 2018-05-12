# go-shared-library-sample

## Linux�r���h�菇
### so�쐬
go build -buildmode=c-shared -o lib.so lib.go
��lib.h���쐬�����

### ���s�t�@�C���쐬
gcc lib.so main_linux.c


### ���l
�ϐ�LD_LIBRARY_PATH�̒ǉ����K�v


## Windows�r���h�菇
### �A�[�J�C�u�쐬
go build -buildmode=c-archive -o lib.a lib.go
��lib.h���쐬�����

### dll�쐬
gcc -m64 -shared -o lib.dll lib.def lib.a  -Wl,--allow-multiple-definition -static -lstdc++ -lwinmm -lntdll -lWs2_32

### ���s�t�@�C���쐬
gcc main_windows.c

