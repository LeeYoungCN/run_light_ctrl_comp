#include "run_light_action_iterator.h"
#include "run_light_behavior_ctrl_public_func.h"
#include "run_light_action_ctrl_factory.h"

#define TO_FLOAT(num) static_cast<VOS_FLOAT>(num)
#define TO_U32(num)   static_cast<VOS_UINT32>(num)

VOS_VOID RunLightActionIterator::Init(RunLightColorCtrlBase *colorCtrl, RunLightCtrlTimer &timer)
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

    m_loopNum  = behaviorComp.loopNum;
    if (m_loopNum == LOOP_INFINITE) {
        m_iteratorType = IteratorType::INFINITE;
    } else {
        m_iteratorType = IteratorType::FINITE;
    }

    if (m_actionCtrl != VOS_NULL_PTR) {
        delete m_actionCtrl;
        m_actionCtrl = VOS_NULL_PTR;
    }
    m_actionCtrl = RunLightActionCtrlFactory::GetInstance().CreateRunLightAction(behaviorComp.lightAction);
    if (m_actionCtrl == VOS_NULL_PTR) {
        return;
    }
    if (m_itrTimer.StartTimer(behaviorComp.lightAction.delayTime) == VOS_OK) {
        StartLoop();
    }
}

// 运行下一步
RunningStatus RunLightActionIterator::NextStep(VOS_UINT32 timerName)
{
    if (!m_itrTimer.IsMyTimer(timerName)) {
        return RunningStatus::NOT_MOV;
    }
    if (m_actionCtrl == VOS_NULL_PTR || m_iteratorStatus == RunningStatus::FINISH) {
        m_iteratorStatus = RunningStatus::FINISH;
        return m_iteratorStatus;
    }
    if (m_actionCtrl->NextStep() == ActionStatus::FINISH) {
        NextLoop();
    }
    return m_iteratorStatus;
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

// 开始循环
VOS_VOID RunLightActionIterator::StartLoop()
{
    if (m_actionCtrl == VOS_NULL_PTR) {
        return;
    }
    if (m_actionCtrl->StartAction(m_colorCtrl) != VOS_OK) {
        return;
    }
    m_iteratorStatus = RunningStatus::RUNNING;
}

