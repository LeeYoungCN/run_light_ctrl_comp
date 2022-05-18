#include "run_light_action_iterator.h"

RunLightActionIterator::RunLightActionIterator(VOS_UINT16 lightId)
    :m_runLightColorCtrl(RunLightColorCtrl(lightId))
{}

RunLightActionIterator::RunLightActionIterator(BreathLightPara breathLightPara)
    :m_runLightColorCtrl(RunLightColorCtrl(breathLightPara))
{}

RunLightActionIterator::RunLightActionIterator(BreathLightGroupPara breathLightGroupPara)
    :m_runLightColorCtrl(RunLightColorCtrl(breathLightGroupPara))
{}

RunLightActionIterator::RunLightActionIterator(NormalLightGroupPara normalLightGropuPara)
    :m_runLightColorCtrl(RunLightColorCtrl(normalLightGropuPara))
{}

VOS_VOID RunLightActionIterator::Init(VOS_HANDEL_T handle, VOS_UINT32 lightIndex)
{
    m_itrTimer.Init(handle, lightIndex);
}

// 开始运行动作迭代器
VOS_VOID RunLightActionIterator::StartIterator(const LightBehaviorComp &behaviorComp)
{
    m_lightAction = behaviorComp.lightAction;
    m_loopNum     = behaviorComp.loopNum;
    m_iteratorStatus = RunningStatus::RUNNING;
    if (m_loopNum == LOOP_INFINITE) {
        m_iteratorType = IteratorType::INFINITE;
    }
    m_itrTimer.StartTimer(m_lightAction.delayTime);
    StartLoop();
}

// 运行下一步
RunningStatus RunLightActionIterator::NextStep(VOS_UINT32 timerName)
{
    if (!m_itrTimer.IsMyTimer(timerName)) {
        return RunningStatus::NOT_MOV;
    }
    ActionNextStep();
    if (m_actionStatus == RunningStatus::FINISH) {
        NextLoop();
    }
    return m_iteratorStatus;
}

// 动作下一步
VOS_VOID RunLightActionIterator::ActionNextStep()
{
    if (m_iteratorStatus == RunningStatus::FINISH) {
        m_actionStatus = RunningStatus::FINISH;
    }

    RunningStatus currActionStatus = RunningStatus::RUNNING;
    switch (m_lightAction.actionType) {
        case ActionType::FLASH: {
            currActionStatus = FlashNextStep();
            break;
        }
        case ActionType::NORMAL: {
            currActionStatus = NoarmalNextStep();
            break;
        }
        default: {
            break;
        }
    }
    m_actionStatus = currActionStatus;
}

// 下一循环
VOS_VOID RunLightActionIterator::NextLoop()
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

// 闪烁动作下一步
RunningStatus RunLightActionIterator::FlashNextStep()
{
    m_flashCnt--;
    if (m_flashCnt > 0) {
        m_runLightColorCtrl.SetColor(m_lightColor);
        return RunningStatus::RUNNING;
    }
    if (m_lightColor == LightColor::BLACK) {
        return RunningStatus::FINISH;
    }

    m_lightColor = LightColor::BLACK;
    m_flashCnt = m_lightAction.para2;
    m_runLightColorCtrl.SetColor(m_lightColor);
    return RunningStatus::RUNNING;
}

// 常亮/常灭下一步
RunningStatus RunLightActionIterator::NoarmalNextStep()
{
    return RunningStatus::FINISH;
}

// 开始循环
VOS_VOID RunLightActionIterator::StartLoop()
{
    if (m_iteratorStatus == RunningStatus::FINISH) {
        return;
    }

    m_actionStatus = RunningStatus::RUNNING;
    m_lightColor = m_lightAction.lightColor;
    m_runLightColorCtrl.SetColor(m_lightColor);
    switch (m_lightAction.actionType) {
        case ActionType::FLASH: {
            m_flashCnt = m_lightAction.para1;
            break;
        }
        default: {
            break;
        }
    };
}