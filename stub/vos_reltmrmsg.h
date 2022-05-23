#ifndef VOS_RELTMRMSG_H
#define VOS_RELTMRMSG_H
#include "vos_base.h"
#include "vos_handle.h"
#include "vos_reltmrknl.h"

VOS_UINT32 VOS_ReltmrMsgStart(VOS_RELTMR_T* phTm,
                             VOS_HANDLE_T  Handle,
                             VOS_UINT32    uiLength,
                             VOS_UINT32    uiName,
                             VOS_UINTPTR   uvParam1,
                             VOS_UINTPTR   uvParam2,
                             VOS_UINT8     ucMode);

#endif // VOS_RELTMRMSG_H
