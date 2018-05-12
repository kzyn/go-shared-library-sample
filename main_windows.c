#include <stdio.h>
#include <windows.h>
#include "lib.h"

typedef void (*pfn1)(CloudStorageInfo *);
typedef CloudStorageInfo* (*pfn2)(void);

int main() {
    pfn1 fn1;
    pfn2 fn2;
    CloudStorageInfo *p, info = {
        .StorageType = 'X',
        .LocalFilePath = "XXXXXXXX",
        .available = true,
        .port = 987,
        .len = 9999,
        .size = sizeof(CloudStorageInfo),
        .unixTime = time(NULL),
    };
    strcpy(info.hostName, "localhost");

    printf("main: %c \n", info.StorageType);
    printf("main: %s \n", info.LocalFilePath);
    printf("main: %d \n", info.available);
    printf("main: %s \n", info.hostName);
    printf("main: %d \n", info.port);
    printf("main: %d \n", info.len);
    printf("main: %d \n", info.size);
    printf("main: %d \n", info.unixTime);

    HMODULE h = LoadLibrary("lib.dll");
    fn1 = (pfn1)GetProcAddress(h, "PutStruct");
    fn1(&info);

    fn2 = (pfn2)GetProcAddress(h, "NewStruct");
    p = (CloudStorageInfo *)fn2();
    printf("main: %c \n", p->StorageType);
    printf("main: %s \n", p->LocalFilePath);
    printf("main: %d \n", p->available);
    printf("main: %s \n", p->hostName);
    printf("main: %d \n", p->port);
    printf("main: %d \n", p->len);
    printf("main: %d \n", p->size);
    printf("main: %d \n", p->unixTime);
    free(p->LocalFilePath);
    free(p);

    return 0;
}