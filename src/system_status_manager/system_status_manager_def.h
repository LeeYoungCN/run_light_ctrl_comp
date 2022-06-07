#ifndef SYSTEM_STATUS_MANAGER_DEF_H
#define SYSTEM_STATUS_MANAGER_DEF_H
#include "vos_base.h"

union SigVal {
    VOS_UINT32 uintVal;
    VOS_INT32  sintVal;
    VOS_FLOAT  floatVal;
};

struct RlcCompSigInfo {
    VOS_UINT16 sigId;
    SigVal     sigVal;
};

struct RlcComAlmInfo {
    VOS_UINT16 almId;
    VOS_UINT32 almStatus;
};

struct EquipSigCfg {
    VOS_UINT16      typeId;
    RlcCompSigInfo *sigInfoArr;
    VOS_UINT32      sigInfoNum;
    RlcComAlmInfo  *almInfoArr;
    VOS_UINT32      almInfoNum;
};

#endif // SYSTEM_STATUS_MANAGER_DEF_H