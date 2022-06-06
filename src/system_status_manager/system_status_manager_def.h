#ifndef SYSTEM_STATUS_MANAGER_DEF_H
#define SYSTEM_STATUS_MANAGER_DEF_H
#include "vos_base.h"

union SigVal {
    VOS_UINT32 uintVal;
    VOS_INT32  sintVal;
    VOS_FLOAT  floatVal;
};

struct SigInfo {
    VOS_UINT16 sigId;
    SigVal     sigVal;
};

struct EquipSigCfg {
    VOS_UINT16 typeId;
    SigInfo   *setSigInfo;
    VOS_UINT32 setSigNum;
    SigInfo   *almSigInfo;
    VOS_UINT32 almSigNum;
};

#endif // SYSTEM_STATUS_MANAGER_DEF_H