#include "LedDriver.h"
#include <stdio.h>

VOS_VOID DRV_LedCtl(VOS_UINT16 ledId, VOS_UINT8 u8Status)
{
    printf("Led%u %s\n", ledId, (u8Status == LED_ON ? "ON" : "OFF"));
}

VOS_INT32 DRV_PwmDutyWrite(VOS_UINT16 u16GptTimeId, VOS_UINT8 u8ChannelNo, VOS_UINT32 u32Compare)
{
    return 0;
}
