#include "run_light_action_iterator.h"
#include "run_light_behavior_ctrl_public_func.h"

#define TO_FLOAT(num) static_cast<VOS_FLOAT>(num)
#define TO_U32(num)   static_cast<VOS_UINT32>(num)

VOS_VOID RunLightActionIterator::Init(RunLightColorCtrl &colorCtrl, RunLightCtrlTimer &timer)
{
    m_colorCtrl = colorCtrl;
    m_itrTimer = timer;
}

// 开始运行动作迭代器
VOS_VOID RunLightActionIterator::StartIterator(const LightBehaviorComp &behaviorComp)
{
    // 校验参数
    if (!IsValidBehaviorComp(behaviorComp)) {
        return;
    }

    m_lightAction = behaviorComp.lightAction;
    m_loopNum     = behaviorComp.loopNum;
    m_iteratorStatus = RunningStatus::RUNNING;
    if (m_loopNum == LOOP_INFINITE) {
        m_iteratorType = IteratorType::INFINITE;
    } else {
        m_iteratorType = IteratorType::FINITE;
    }
    if (m_itrTimer.StartTimer(m_lightAction.delayTime) == VOS_OK) {
        StartLoop();
    }
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
        case ActionType::CONST: {
            currActionStatus = NoarmalNextStep();
            break;
        }
        case ActionType::BREATH: {
            currActionStatus = BreathNextStep();
            break;
        }
        default: {
            break;
        }
    }
    m_actionStatus = currActionStatus;
}

RunningStatus RunLightActionIterator::BreathNextStep()
{
    m_counter--;
    if (m_counter > 0) {
        m_colorCtrl.SetColor(m_lightColor, CalBrightPercent());
        return RunningStatus::RUNNING;
    }
    if (m_brightDelta < 0) {
        return RunningStatus::FINISH;
    }
    m_counter = m_lightAction.para2;
    m_brightPercent = MAX_BRIGHT_PERCENT_FLOAT;
    m_brightDelta = -(MAX_BRIGHT_PERCENT_FLOAT / TO_FLOAT(m_lightAction.para2));
    m_colorCtrl.SetColor(m_lightColor, MAX_LUMINANCE);
    return RunningStatus::RUNNING;
}

VOS_UINT32 RunLightActionIterator::CalBrightPercent()
{
    m_brightPercent += m_brightDelta;
    if (m_brightPercent < 0) {
        return 0;
    } else if (TO_U32(m_brightPercent) > MAX_LUMINANCE) {
        return MAX_LUMINANCE;
    } else {
        return TO_U32(m_brightPercent);
    }
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

    if (m_loopNum > 0) {
        StartLoop();
    } else {
        m_iteratorStatus = RunningStatus::FINISH;
        m_itrTimer.StopTimer();
    }
}

// 闪烁动作下一步
RunningStatus RunLightActionIterator::FlashNextStep()
{
    m_counter--;
    if (m_counter > 0) {
        m_colorCtrl.SetColor(m_lightColor);
        return RunningStatus::RUNNING;
    }
    if (m_lightColor == LightColor::BLACK) {
        return RunningStatus::FINISH;
    }

    m_lightColor = LightColor::BLACK;
    m_counter = m_lightAction.para2;
    m_colorCtrl.SetColor(m_lightColor);
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
    switch (m_lightAction.actionType) {
        case ActionType::CONST: {
            m_colorCtrl.SetColor(m_lightColor);
            break;
        }
        case ActionType::FLASH: {
            m_colorCtrl.SetColor(m_lightColor);
            m_counter = m_lightAction.para1;
            break;
        }
        case ActionType::BREATH: {
            m_counter = m_lightAction.para1;
            m_brightPercent = 0;
            m_brightDelta = MAX_BRIGHT_PERCENT_FLOAT / TO_FLOAT(m_lightAction.para1);
            m_colorCtrl.SetColor(m_lightColor, m_brightPercent);
            break;
        }
        default:
            break;
    };
}
