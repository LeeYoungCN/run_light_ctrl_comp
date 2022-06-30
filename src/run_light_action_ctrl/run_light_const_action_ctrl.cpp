#include "run_light_const_action_ctrl.h"

RunLightConstActionCtrl::RunLightConstActionCtrl(const LightAction &actionPara)
    : m_actionPara(actionPara)
{}

VOS_UINT32 RunLightConstActionCtrl::StartLoop(RunLightColorCtrlBase *colorCtrlInst)
{
    if (Init(colorCtrlInst) != VOS_OK) {
        return VOS_ERR;
    }

    SetColor(m_actionPara.lightColor, m_actionPara.luminace);
    return VOS_OK;
}

ActionStatus RunLightConstActionCtrl::NextStep()
{
    return ActionStatus::FINISH;
}

VOS_BOOL RunLightConstActionCtrl::IsValidActionPara()
{
    return VOS_TRUE;
}
