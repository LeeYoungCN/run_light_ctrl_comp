#include "run_light_flash_action_ctrl.h"

RunLightFlashActionCtrl::RunLightFlashActionCtrl(const LightAction &actionPara)
    : m_actionPara(actionPara)
{}

VOS_UINT32 RunLightFlashActionCtrl::StartAction(RunLightColorCtrlBase *colorCtrlInst)
{
    if (Init(colorCtrlInst) != VOS_OK) {
        return VOS_ERR;
    }
    m_lightColor = m_actionPara.lightColor;
    m_counter.SetCountNum(m_actionPara.para1);
    SetColor(m_lightColor, MAX_LUMINANCE);
    return VOS_OK;
}

ActionStatus RunLightFlashActionCtrl::NextStep()
{
    m_counter.Count();
    if (!m_counter.IsFinish()) {
        SetColor(m_lightColor, MAX_LUMINANCE);
        return ActionStatus::RUNNING;
    }

    if (m_lightColor == LightColor::BLACK) {
        return ActionStatus::FINISH;
    }

    m_lightColor = LightColor::BLACK;
    m_counter.SetCountNum(m_actionPara.para2);
    SetColor(m_lightColor, MAX_LUMINANCE);
    return ActionStatus::RUNNING;
}

VOS_BOOL RunLightFlashActionCtrl:: IsValidPara()
{
    if ((m_actionPara.lightColor == LightColor::BLACK) ||
        (m_actionPara.para1 == 0) ||
        (m_actionPara.para2 == 0)
    ) {
        return VOS_FALSE;
    }
    return VOS_TRUE;
}
