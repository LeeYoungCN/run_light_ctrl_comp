#ifndef EMAP_SO_LOG_H
#define EMAP_SO_LOG_H
#include "vos_base.h"
#include "vos_base.h"

#define EMAP_LOG(modId, level, fmt, ...) EMAP_LogPrint(modId, level, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

const VOS_UINT8 EMAP_PRINT_LEVEL_DEBUG   = 1;
const VOS_UINT8 EMAP_PRINT_LEVEL_INFO    = 2;
const VOS_UINT8 EMAP_PRINT_LEVEL_WARNING = 3;
const VOS_UINT8 EMAP_PRINT_LEVEL_ERROR   = 4;
const VOS_UINT8 EMAP_PRINT_LEVEL_EVENT   = 5;

VOS_VOID EMAP_LogPrint(
    VOS_UINT16 u16ModId,
    VOS_UINT8 u8Level,
    const VOS_CHAR *fileName,
    VOS_UINT32 u32Line,
    const VOS_CHAR *fmt, ...);

#endif // EMAP_SO_LOG_H
