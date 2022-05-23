#ifndef VOS_RELTMRKNL_H
#define VOS_RELTMRKNL_H
#include "vos_base.h"

typedef VOS_VOID *VOS_RELTMR_T;
#define VOS_RELTIMER_NOLOOP 0x0
#define VOS_RELTIMER_LOOP 0x1

VOS_UINT32 VOS_ReltmrStop(VOS_RELTMR_T *phTm);

#endif // VOS_RELTMRKNL_H
