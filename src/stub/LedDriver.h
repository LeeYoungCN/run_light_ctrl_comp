#ifndef LEDDRIVER_H
#define LEDDRIVER_H
#include "vos_base.h"

#define LED_ON 1
#define LED_OFF 0

VOS_VOID DRV_LedCtl(VOS_UINT16 ledId, VOS_UINT8 u8Status);
VOS_INT32 DRV_PwmDutyWrite(VOS_UINT16 u16GptTimeId, VOS_UINT8 u8ChannelNo, VOS_UINT32 u32Compare);

#endif // LEDDRIVER_H
