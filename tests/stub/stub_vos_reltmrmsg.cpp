#include "vos_reltmrknl.h"
#include "vos_handle.h"
#include "run_light_ctrl_comp_log.h"

VOS_UINT32 VOS_ReltmrMsgStart(VOS_RELTMR_T* phTm,
                             VOS_HANDLE_T  Handle,
                             VOS_UINT32    uiLength,
                             VOS_UINT32    uiName,
                             VOS_UINTPTR   uvParam1,
                             VOS_UINTPTR   uvParam2,
                             VOS_UINT8     ucMode)
{
    *phTm = reinterpret_cast<VOS_VOID *>(&uiName);
    return VOS_OK;
}
