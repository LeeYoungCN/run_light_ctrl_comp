#include "light_running_ctrl_base.h"

LightRunningCtrlBase::LightRunningCtrlBase() {}

LightRunningCtrlBase::~LightRunningCtrlBase() {}

VOS_VOID LightRunningCtrlBase::Init(VOS_HANDEL_T handle, VOS_UINT32 lightIndex)
{
    LightRunningCtrlIterator::Init(handle, lightIndex);
}

VOS_VOID LightRunningCtrlBase::RefreshActionGroup(const LigtActionGroup &LightActionGroup)
{
    m_currActionGroup = LightActionGroup;
    m_runStage = 0;
    SetAction(m_currActionGroup.componentArr[m_runStage]);
}

VOS_VOID LightRunningCtrlBase::SetColor(const LightColor lightColor)
{
    cout << "SetColor = " << (VOS_UINT32)(lightColor) << endl;
}

VOS_VOID LightRunningCtrlBase::SetAction(const LightAction &lightAction)
{
    StartIterator(lightAction, LOOP_INFINITE);
}

VOS_VOID LightRunningCtrlBase::SetAction(const ActionGroupComp &actionComp)
{
    StartIterator(actionComp.lightAction, actionComp.loopNum);
}

VOS_VOID LightRunningCtrlBase::Run()
{
    if (NextStep() != RunningStatus::FINISH) {
        return;
    }
    m_runStage++;
    if (m_runStage == m_currActionGroup.componentNum) {
        m_runStage = 0;
    }
    SetAction(m_currActionGroup.componentArr[m_runStage]); 
}
