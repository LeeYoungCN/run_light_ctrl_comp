#include "run_light_action_iterator.h"
#include "run_light_behavior_ctrl_public_func.h"
#include "run_light_action_ctrl_factory.h"

#define TO_FLOAT(num) static_cast<VOS_FLOAT>(num)
#define TO_U32(num)   static_cast<VOS_UINT32>(num)
#define INST(className) className::GetInstance()

RunLightActionIterator::~RunLightActionIterator()
{
    StopIterator();
}

VOS_VOID RunLightActionIterator::Init(RunLightColorCtrlBase *colorCtrl, RunLightCtrlTimer &timer)
{
    m_colorCtrl = colorCtrl;
    m_itrTimer  = timer;
}

// 开始运行动作迭代器
VOS_VOID RunLightActionIterator::StartIterator(const LightBehaviorComp &behaviorComp)
{
    if (behaviorComp.loopNum == 0) {
        return;
    }

    StopIterator();

    m_loopNum  = behaviorComp.loopNum;
    m_iteratorType = (m_loopNum == LOOP_INFINITE ? IteratorType::INFINITE : IteratorType::FINITE);
    m_actionCtrl = INST(RunLightActionCtrlFactory).CreateRunLightAction(behaviorComp.lightAction);
    if (m_actionCtrl == VOS_NULL_PTR) {
        return;
    }

    if (m_itrTimer.StartTimer(behaviorComp.lightAction.delayTime) == VOS_OK) {
        StartLoop();
    }
}

VOS_VOID RunLightActionIterator::StopIterator()
{
    if (m_actionCtrl != VOS_NULL_PTR) {
        delete m_actionCtrl;
        m_actionCtrl = VOS_NULL_PTR;
    }
    m_itrTimer.StopTimer();
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
