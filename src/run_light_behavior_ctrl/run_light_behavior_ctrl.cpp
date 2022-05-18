#include "run_light_behavior_ctrl.h"

RunLightBehaviorCtrl::RunLightBehaviorCtrl(VOS_UINT16 lightId)
    : m_actionItr(RunLightActionIterator(lightId))
{}
RunLightBehaviorCtrl::RunLightBehaviorCtrl(BreathLightPara breathLightPara)
    : m_actionItr(RunLightActionIterator(breathLightPara))
{}

RunLightBehaviorCtrl::RunLightBehaviorCtrl(BreathLightGroupPara breathLightGroupPara)
    : m_actionItr(RunLightActionIterator(breathLightGroupPara))
{}
RunLightBehaviorCtrl::RunLightBehaviorCtrl(NormalLightGroupPara normalLightGropuPara)
    : m_actionItr(RunLightActionIterator(normalLightGropuPara))
{}

// 初始化
VOS_VOID RunLightBehaviorCtrl::Init(VOS_HANDEL_T handle, VOS_UINT32 lightIndex)
{
    m_actionItr.Init(handle, lightIndex);
}

// 设置行为
VOS_VOID RunLightBehaviorCtrl::SetBehavior(const LigtBehavior &newBehavior)
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
