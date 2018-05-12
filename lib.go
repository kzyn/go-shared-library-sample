package main

/*
#include "struct.h"
*/
import "C"

import (
	"fmt"
	"unsafe"
)

type CloudStorageInfo struct {
	StorageType   byte
	LocalFilePath string
	available     bool
	hostName      string
	port          uint16
	len           int32
	size          int64
	unixTime      int32
}

//export PutStruct
func PutStruct(info *C.CloudStorageInfo) {
	goInfo := CloudStorageInfo{
		StorageType:   byte(info.StorageType),
		LocalFilePath: C.GoString(info.LocalFilePath),
		available:     bool(info.available),
		hostName:      C.GoString(&info.hostName[0]),
		port:          uint16(info.port),
		len:           int32(info.len),
		size:          int64(info.size),
		unixTime:      int32(info.unixTime),
	}
	fmt.Printf("lib:  %#U \n", goInfo.StorageType)
	fmt.Println("lib: ", goInfo.LocalFilePath)
	fmt.Println("lib: ", goInfo.available)
	fmt.Println("lib: ", goInfo.hostName)
	fmt.Println("lib: ", goInfo.port)
	fmt.Println("lib: ", goInfo.len)
	fmt.Println("lib: ", goInfo.size)
	fmt.Println("lib: ", goInfo.unixTime)
}

//export NewStruct
func NewStruct() *C.CloudStorageInfo {
	v := (*C.CloudStorageInfo)(C.malloc(C.size_t(unsafe.Sizeof(C.CloudStorageInfo{}))))
	if v != nil {
		*v = C.CloudStorageInfo{
			StorageType:   C.uchar('A'),
			LocalFilePath: C.CString("aaaaaaa"),
			available:     C.bool(true),
			port:          C.ushort(3333),
			len:           C.int(8888),
			size:          C.size_t(987654),
			unixTime:      C.time_t(1525426179),
		}
		// 他にいい方法ないかな
		for i, d := range "localhost.xxx.co.jp" {
			v.hostName[i] = C.char(d)
		}
	}
	return v
}

func main() {

}
