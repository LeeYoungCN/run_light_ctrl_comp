#include "breath_light_color_ctrl.h"

BreathLightColorCtrl::BreathLightColorCtrl(const BreathLightPara &lightPara)
    : m_lightPara(lightPara)
{}

VOS_BOOL BreathLightColorCtrl::Init(VOS_UINT32 lightIdex)
{
    return VOS_TRUE;
}

VOS_VOID BreathLightColorCtrl::SetColor(LightColor colorType, VOS_UINT32 luminance)
{
    ;
}

VOS_UINT32 BreathLightColorCtrl::InitPwmPara()
{
    return VOS_OK;
}
