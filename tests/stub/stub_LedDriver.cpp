#include "LedDriver.h"
#include "run_light_ctrl_comp_log.h"
#include "light_status_manager.h"

VOS_VOID DRV_LedCtl(VOS_UINT16 ledId, VOS_UINT8 u8Status)
{
    LightStatusManager::GetInstance().SetLightStatus(ledId, u8Status);
}
