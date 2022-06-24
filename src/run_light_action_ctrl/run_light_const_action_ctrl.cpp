#include "run_light_const_action_ctrl.h"

RunLightConstActionCtrl::RunLightConstActionCtrl(const LightActionPara &actionPara)
    : m_actionPara(actionPara)
{}

VOS_UINT32 RunLightConstActionCtrl::StartLoop()
{
    ;
}

ActionStatus RunLightConstActionCtrl::NextStep()
{
    return ActionStatus::FINISH;
}
