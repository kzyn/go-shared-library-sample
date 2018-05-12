#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main() {
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

    PutStruct(&info);

    p = (CloudStorageInfo *)NewStruct();
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