#include "run_light_color_ctrl.h"
#include "DevId.h"
#include "LedDriver.h"
#include "PwmDriver.h"

namespace {
    struct LightColorCtrlPara {
        LightColor  lightColor;
        LightStatus redStatus;
        LightStatus greenStatus;
        LightStatus blueStatus;
    };

    const LightColorCtrlPara LIGHT_COLOR_CTRL_PARA_LIST[] = {
        {LightColor::RED,    LightStatus::ON,  LightStatus::OFF, LightStatus::OFF},
        {LightColor::GREEN,  LightStatus::OFF, LightStatus::ON,  LightStatus::OFF},
        {LightColor::BLUE,   LightStatus::OFF, LightStatus::OFF, LightStatus::ON},
        {LightColor::YELLOW, LightStatus::ON,  LightStatus::ON,  LightStatus::OFF},
        {LightColor::PURPLE, LightStatus::ON,  LightStatus::OFF, LightStatus::ON},
        {LightColor::CYAN,   LightStatus::OFF, LightStatus::ON,  LightStatus::ON},
        {LightColor::WHITE,  LightStatus::ON,  LightStatus::ON,  LightStatus::ON},
        {LightColor::BLACK,  LightStatus::OFF, LightStatus::OFF, LightStatus::OFF},
    };

    const VOS_UINT32 LIST_LEN = U16_ITEM_OF(LIGHT_COLOR_CTRL_PARA_LIST);
}

RunLightColorCtrl::RunLightColorCtrl(VOS_UINT16 lightId)
    : m_lightType(LightType::NORMAL_LIGHT),
      m_normalLightGropuPara({lightId, 0, 0})
{}

RunLightColorCtrl::RunLightColorCtrl(BreathLightPara breathLightPara)
    : m_lightType(LightType::BREATH_LIGHT),
      m_breathLightGroupPara({breathLightPara, {0}, {0}})
{}

RunLightColorCtrl::RunLightColorCtrl(BreathLightGroupPara breathLightGroupPara)
    : m_lightType(LightType::BREATH_LIGHT_GROUP),
      m_breathLightGroupPara(breathLightGroupPara)
{}

RunLightColorCtrl::RunLightColorCtrl(NormalLightGroupPara normalLightGropuPara)
    : m_lightType(LightType::NORMAL_LIGHT_GROUP),
      m_normalLightGropuPara(normalLightGropuPara)
{}

 VOS_VOID RunLightColorCtrl::Init(VOS_UINT32 lightIndex)
 {
     m_lightIndex = lightIndex;
 }

VOS_VOID RunLightColorCtrl::SetColor(LightColor lightColor, VOS_FLOAT brightPct)
{
    switch (m_lightType) {
        case LightType::NORMAL_LIGHT: {
            CtrlNormalLightColor(lightColor);
            break;
        }
        case LightType::BREATH_LIGHT: {
            CtrlBreathLightColor(lightColor, brightPct);
            break;
        }
        case LightType::NORMAL_LIGHT_GROUP: {
            CtrlNormalLightGroupColor(lightColor);
            break;
        }
        default: {
            CtrlBreathLightGroupColor(lightColor, brightPct);
            break;
        }
    }
}

VOS_VOID RunLightColorCtrl::CtrlNormalLightColor(LightColor lightColor)
{
    if (lightColor == LightColor::BLACK) {
        CtrlNormalLightStatus(m_normalLightGropuPara.redId, LightStatus::OFF);
    } else {
        CtrlNormalLightStatus(m_normalLightGropuPara.redId, LightStatus::ON);
    }
}

VOS_VOID RunLightColorCtrl::CtrlNormalLightGroupColor(LightColor lightColor)
{
    for (VOS_UINT32 i = 0; i < LIST_LEN; i++) {
        if (LIGHT_COLOR_CTRL_PARA_LIST[i].lightColor != lightColor) {
            continue;
        }
        CtrlNormalLightStatus(m_normalLightGropuPara.redId,   LIGHT_COLOR_CTRL_PARA_LIST[i].redStatus);
        CtrlNormalLightStatus(m_normalLightGropuPara.greenId, LIGHT_COLOR_CTRL_PARA_LIST[i].greenStatus);
        CtrlNormalLightStatus(m_normalLightGropuPara.blueId,  LIGHT_COLOR_CTRL_PARA_LIST[i].blueStatus);
        break;
    }
}

VOS_VOID RunLightColorCtrl::CtrlNormalLightStatus(VOS_UINT16 lightId, LightStatus status)
{
    if (lightId < LED0_ID || lightId >= LED_NUM) {
        return;
    }

    if (status == LightStatus::ON) {
        DRV_LedCtl(lightId, LED_ON);
    } else {
        DRV_LedCtl(lightId, LED_OFF);
    }
}

VOS_VOID RunLightColorCtrl::CtrlBreathLightColor(LightColor lightColor, VOS_FLOAT brightPct)
{
    if (lightColor == LightColor::BLACK) {
        CtrlBreathLightStatus(m_breathLightGroupPara.redLight, LightStatus::OFF, brightPct);
    } else {
        CtrlBreathLightStatus(m_breathLightGroupPara.redLight, LightStatus::ON,  brightPct);
    }
}

VOS_VOID RunLightColorCtrl::CtrlBreathLightGroupColor(LightColor lightColor, VOS_FLOAT brightPct)
{
    for (VOS_UINT32 i = 0; i < LIST_LEN; i++) {
        if (LIGHT_COLOR_CTRL_PARA_LIST[i].lightColor != lightColor) {
            continue;
        }
        CtrlBreathLightStatus(m_breathLightGroupPara.redLight,   LIGHT_COLOR_CTRL_PARA_LIST[i].redStatus,   brightPct);
        CtrlBreathLightStatus(m_breathLightGroupPara.greenLight, LIGHT_COLOR_CTRL_PARA_LIST[i].greenStatus, brightPct);
        CtrlBreathLightStatus(m_breathLightGroupPara.blueLight,  LIGHT_COLOR_CTRL_PARA_LIST[i].blueStatus,  brightPct);
        break;
    }
}

VOS_VOID RunLightColorCtrl::CtrlBreathLightStatus(BreathLightPara lightPara, LightStatus lightStatus, VOS_FLOAT brightPct)
{
    VOS_FLOAT compare = 0;
    if (lightStatus != LightStatus::ON) {
        compare = brightPct * static_cast<VOS_FLOAT>(lightPara.maxCompare) / MAX_BRIGHT_PERCENT;
    }
    DRV_PwmDutyWrite(lightPara.gptId, lightPara.gptchl, static_cast<VOS_UINT32>(compare));
}
