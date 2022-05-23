#ifndef PWMDRIVER_H
#define PWMDRIVER_H
#include "vos_base.h"

VOS_INT32 DRV_PwmDutyWrite(VOS_UINT16 u16GptTimeId, VOS_UINT8 u8ChannelNo, VOS_UINT32 u32Compare);

#endif // PWMDRIVER_H
