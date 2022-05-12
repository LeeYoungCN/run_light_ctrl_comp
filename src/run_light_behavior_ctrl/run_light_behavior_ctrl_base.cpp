#include "run_light_behavior_ctrl_base.h"

RunLightBehaviorCtrlBase::RunLightBehaviorCtrlBase() {}

RunLightBehaviorCtrlBase::~RunLightBehaviorCtrlBase() {}

VOS_VOID RunLightBehaviorCtrlBase::Init(VOS_HANDEL_T handle, VOS_UINT32 lightIndex)
{
    RunLightBehaviorCtrlIterator::Init(handle, lightIndex);
}

VOS_VOID RunLightBehaviorCtrlBase::SetBehavior(const LigtBehavior &newBehavior)
{
    m_currBehavior = newBehavior;
    m_runStage = 0;
    StartIterator(m_currBehavior.componentArr[m_runStage]);
}

VOS_VOID RunLightBehaviorCtrlBase::SetColor(const LightColor lightColor)
{
    cout << "SetColor = " << (VOS_UINT32)(lightColor) << endl;
}

VOS_VOID RunLightBehaviorCtrlBase::Run()
{
    if (NextStep() != RunningStatus::FINISH) {
        return;
    }
    m_runStage++;
    if (m_runStage == m_currBehavior.componentNum) {
        m_runStage = 0;
    }
    StartIterator(m_currBehavior.componentArr[m_runStage]);
}
