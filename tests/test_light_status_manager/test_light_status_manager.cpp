#include "test_light_status_manager.h"
#include "DevId.h"
#include "LedDriver.h"
#include "run_light_ctrl_comp_log.h"

LightStatusManager &LightStatusManager::GetInstance()
{
    static LightStatusManager inst;
    return inst;
}

LightStatusManager::LightStatusManager()
{
    for (VOS_UINT32 lightId = LED0_ID; lightId < LED_NUM; lightId++) {
        m_statusMap.emplace(lightId, LED_OFF);
    }
}

VOS_VOID LightStatusManager::SetLightStatus(VOS_UINT32 lightId, VOS_UINT32 status)
{
    m_statusMap.at(lightId) = status;
    RLC_LOG_DEBUG("Set led;OK;Idx=%u, status=%u;", lightId, status);
}

VOS_UINT32 LightStatusManager::GetLightStatus(VOS_UINT32 lightId)
{
    VOS_UINT32 status = m_statusMap.at(lightId);
    return status;
}
