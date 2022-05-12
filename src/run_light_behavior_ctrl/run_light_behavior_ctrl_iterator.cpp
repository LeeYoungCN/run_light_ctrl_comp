#include "run_light_behavior_ctrl_iterator.h"

VOS_VOID RunLightBehaviorCtrlIterator::Init(VOS_HANDEL_T handle, VOS_UINT32 lightIndex)
{
    m_itrTimer.Init(handle, lightIndex);
}

VOS_VOID RunLightBehaviorCtrlIterator::StartIterator(const LightBehaviorComp &behaviorComp)
{
    m_lightAction = behaviorComp.lightAction;
    m_loopNum = behaviorComp.loopNum;
    m_iteratorStatus = RunningStatus::RUNNING;
    if (m_loopNum == LOOP_INFINITE) {
        m_iteratorType = IteratorType::INFINITE;
    }
    m_itrTimer.StartTimer(m_lightAction.delayTime);
    StartLoop();
}


RunningStatus RunLightBehaviorCtrlIterator::NextStep(VOS_UINT32 timerName)
{
    if (m_itrTimer.IsMyTimer(timerName) != VOS_OK) {
        return RunningStatus::NOT_MOV;
    }
    ActionNextStep();
    if (m_actionStatus == RunningStatus::FINISH) {
        NextLoop();
    }
    return m_iteratorStatus;
}

VOS_VOID RunLightBehaviorCtrlIterator::ActionNextStep()
{
    if (m_iteratorStatus == RunningStatus::FINISH) {
        m_actionStatus = RunningStatus::FINISH;
    }

    RunningStatus currActionStatus = RunningStatus::RUNNING;
    switch(m_lightAction.actionType) {
        case (ActionType::FLASH): {
            currActionStatus = FlashNextStep();
            break;
        }
        case (ActionType::NORMAL): {
            currActionStatus = NoarmalNextStep();
            break;
        }
        default: {
            break;
        }
    }
    m_actionStatus = currActionStatus;
}

VOS_VOID RunLightBehaviorCtrlIterator::NextLoop()
{
    if (m_iteratorStatus == RunningStatus::FINISH || m_loopNum == 0) {
        m_iteratorStatus = RunningStatus::FINISH;
    }

    if (m_iteratorType == IteratorType::FINITE) {
        m_loopNum--;
    }
    if (m_loopNum  > 0) {
        StartLoop();
    } else {
        m_iteratorStatus = RunningStatus::FINISH;
        m_itrTimer.StopTimer();
    }
}

RunningStatus RunLightBehaviorCtrlIterator::FlashNextStep()
{
    m_flashCnt--;
    if (m_flashCnt > 0) {
        SetColor(m_lightColor);
        return RunningStatus::RUNNING;
    }
    if (m_lightColor == LightColor::BLACK) {
        return RunningStatus::FINISH;
    }

    m_lightColor = LightColor::BLACK;
    m_flashCnt = m_lightAction.para2;
    SetColor(m_lightColor);
    return RunningStatus::RUNNING;
}

RunningStatus RunLightBehaviorCtrlIterator::NoarmalNextStep()
{
    return RunningStatus::FINISH;
}

VOS_VOID RunLightBehaviorCtrlIterator::StartLoop()
{
    if (m_iteratorStatus == RunningStatus::FINISH) {
        return;
    }

    m_actionStatus = RunningStatus::RUNNING;
    m_lightColor = m_lightAction.lightColor;
    SetColor(m_lightColor);
    switch(m_lightAction.actionType) {
        case(ActionType::FLASH) : {
            m_flashCnt = m_lightAction.para1;
            break;
        }
        default: {
            break;
        }
    };
}
