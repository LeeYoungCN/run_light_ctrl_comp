#ifndef RUN_LIGHT_CTRL_COMP_LOG_H
#define RUN_LIGHT_CTRL_COMP_LOG_H
#include "emap_so_log.h"

const VOS_UINT32 RLC_COMP_LOG_DEFAULT_MOD_ID = 0;

inline VOS_UINT32 GetModId()
{
    return RLC_COMP_LOG_DEFAULT_MOD_ID;
}

#define RLC_LOG_DEBUG(fmt, ...)   EMAP_LOG(GetModId(), EMAP_PRINT_LEVEL_DEBUG,   fmt, ##__VA_ARGS__)
#define RLC_LOG_INFO(fmt, ...)    EMAP_LOG(GetModId(), EMAP_PRINT_LEVEL_INFO,    fmt, ##__VA_ARGS__)
#define RLC_LOG_WARNING(fmt, ...) EMAP_LOG(GetModId(), EMAP_PRINT_LEVEL_WARNING, fmt, ##__VA_ARGS__)
#define RLC_LOG_ERROR(fmt, ...)   EMAP_LOG(GetModId(), EMAP_PRINT_LEVEL_ERROR,   fmt, ##__VA_ARGS__)
#define RLC_LOG_EVENT(fmt, ...)   EMAP_LOG(GetModId(), EMAP_PRINT_LEVEL_EVENT,   fmt, ##__VA_ARGS__)

#endif // RUN_LIGHT_CTRL_COMP_LOG_H
