#include "LedDriver.h"
#include "run_light_ctrl_comp_log.h"

VOS_VOID DRV_LedCtl(VOS_UINT16 ledId, VOS_UINT8 u8Status)
{
    RLC_LOG_EVENT("Led%u %s", ledId, (u8Status == LED_ON ? "ON" : "OFF"));
}
