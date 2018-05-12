#ifndef _STRUCT_H_
#define _STRUCT_H_

#include <stdbool.h>
#include <time.h>

typedef struct {
    unsigned char       StorageType;
    char *              LocalFilePath;
    bool                available;
    char                hostName[68 + 1];
    unsigned short      port;
    int                 len;
    size_t              size;
    time_t              unixTime;
} CloudStorageInfo;

#endif