#include "run_light_behavior_ctrl.h"
#include "run_light_ctrl_comp_log.h"

RunLightBehaviorCtrl::RunLightBehaviorCtrl(VOS_UINT16 lightId)
    : m_colorCtrl(RunLightColorCtrl(lightId))
{}
RunLightBehaviorCtrl::RunLightBehaviorCtrl(BreathLightPara breathLightPara)
    : m_colorCtrl(RunLightColorCtrl(breathLightPara))
{}

RunLightBehaviorCtrl::RunLightBehaviorCtrl(BreathLightGroupPara breathLightGroupPara)
    : m_colorCtrl(RunLightColorCtrl(breathLightGroupPara))
{}
RunLightBehaviorCtrl::RunLightBehaviorCtrl(NormalLightGroupPara normalLightGropuPara)
    : m_colorCtrl(RunLightColorCtrl(normalLightGropuPara))
{}

// 初始化
VOS_VOID RunLightBehaviorCtrl::Init(VOS_HANDLE_T handle, VOS_UINT32 lightIndex)
{
    m_colorCtrl.Init(lightIndex);
    m_timer.Init(handle, lightIndex);
    m_actionItr.Init(m_colorCtrl, m_timer);
    RLC_LOG_EVENT("Init light behavior ctrl;OK;Index=%u", lightIndex);
}

// 设置行为
VOS_VOID RunLightBehaviorCtrl::SetBehavior(const LightBehavior &newBehavior)
{
    m_currBehavior = newBehavior;
    m_runStage = 0;
    m_actionItr.StartIterator(m_currBehavior.componentArr[m_runStage]);
}

// 运行
VOS_VOID RunLightBehaviorCtrl::Run(VOS_UINT32 timerName)
{
    if (m_actionItr.NextStep(timerName) != RunningStatus::FINISH) {
        return;
    }
    m_runStage++;
    if (m_runStage == m_currBehavior.componentNum) {
        m_runStage = 0;
    }
    m_actionItr.StartIterator(m_currBehavior.componentArr[m_runStage]);
}
