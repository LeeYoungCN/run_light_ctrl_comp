#include "run_light_breath_action_ctrl.h"
#include "run_light_color_ctrl.h"

RunLightBreathActionCtrl::RunLightBreathActionCtrl(const LightAction &actionPara)
    : m_actionPara(actionPara) 
{}

VOS_UINT32 RunLightBreathActionCtrl::StartAction(RunLightColorCtrlBase *colorCtrlInst)
{
    if (Init(colorCtrlInst) != VOS_OK) {
        return VOS_ERR;
    }
    m_counter.SetCountNum(m_actionPara.para1);
    m_operate = BreathOperate::ADD;
    m_lightLuminance = MIN_LUMINANCE * LUMINANCE_PRECISION;
    m_luminanceDelta = (MAX_LUMINANCE - MIN_LUMINANCE) * LUMINANCE_PRECISION / m_actionPara.para1;
    SetColor(m_actionPara.lightColor, MIN_LUMINANCE);
    return VOS_OK;
}

ActionStatus RunLightBreathActionCtrl::NextStep()
{
    m_counter.Count();
    if (!m_counter.IsFinish()) {
        SetColor(m_lightColor, MAX_LUMINANCE);
        return ActionStatus::RUNNING;
    }

    if (m_operate == BreathOperate::SUB) {
        return ActionStatus::FINISH;
    }

    m_counter.SetCountNum(m_actionPara.para2);
    m_operate = BreathOperate::SUB;
    m_lightLuminance = MAX_LUMINANCE * LUMINANCE_PRECISION;
    m_luminanceDelta = (MAX_LUMINANCE - MIN_LUMINANCE) * LUMINANCE_PRECISION / m_actionPara.para2;
    SetColor(m_actionPara.lightColor, MAX_LUMINANCE);
    return ActionStatus::RUNNING;
}

VOS_BOOL RunLightBreathActionCtrl:: IsValidPara()
{
    if ((m_actionPara.lightColor == LightColor::BLACK) ||
        (m_actionPara.para1 == 0) ||
        (m_actionPara.para2 == 0)
    ) {
        return VOS_FALSE;
    }
    return VOS_TRUE;
}
