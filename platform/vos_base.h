#ifndef VOS_BASE_H
#define VOS_BASE_H
#include <iostream>
using namespace std;

typedef unsigned int VOS_UINT32;
typedef int VOS_INT32;
typedef unsigned short VOS_UINT16;
typedef short VOS_INT16;
typedef unsigned char VOS_UINT8;
typedef void VOS_VOID;
typedef VOS_UINT32 VOS_UINTPTR;
typedef char VOS_CHAR;
typedef float VOS_FLOAT;

#define VOS_OK 0
#define VOS_ERR 1

typedef bool VOS_BOOL;
#define VOS_TRUE  true
#define VOS_FALSE false
#define VOS_NULL_PTR 0
#endif // VOS_BASE_H