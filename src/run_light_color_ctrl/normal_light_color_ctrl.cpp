#include "normal_light_color_ctrl.h"
#include "DevId.h"
#include "LedDriver.h"

NormalLightColorCtrl::NormalLightColorCtrl(VOS_UINT16 lightId)
    : m_lightId(lightId)
{}

VOS_BOOL NormalLightColorCtrl::Init(VOS_UINT32 lightIndex)
{
    m_lightIndex = lightIndex;
    return ((m_lightId >= LED0_ID) && (m_lightId < LED_NUM));
}

VOS_VOID NormalLightColorCtrl::SetColor(LightColor colorType, VOS_UINT32 luminance = MAX_LUMINANCE)
{
    if ((colorType == LightColor::BLACK) || (luminance == 0)) {
        CtrlLightStatus(LightStatus::OFF);
    } else {
        CtrlLightStatus(LightStatus::ON);
    }
}

VOS_VOID NormalLightColorCtrl::CtrlLightStatus(LightStatus status)
{
    if (status == LightStatus::ON) {
        DRV_LedCtl(m_lightId, LED_ON);
    } else {
        DRV_LedCtl(m_lightId, LED_OFF);
    }
}
