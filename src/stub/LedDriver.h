#ifndef LEDDRIVER_H
#define LEDDRIVER_H
#include "vos_base.h"

enum LedId {
    LED0_ID,
    LED1_ID,
    LED2_ID,
    LED3_ID,
    LED_NUM
};

#define LED_ON 0
#define LED_OFF 1

VOS_VOID DRV_LedCtl(VOS_UINT16 ledId, VOS_UINT8 u8Status);
VOS_INT32 DRV_PwmDutyWrite(VOS_UINT16 u16GptTimeId, VOS_UINT8 u8ChannelNo, VOS_UINT32 u32Compare);

#endif // LEDDRIVER_H
