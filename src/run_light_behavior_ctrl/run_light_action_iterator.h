#ifndef RUN_LIGHT_ACTION_ITERATOR_H
#define RUN_LIGHT_ACTION_ITERATOR_H
#include "vos_base.h"
#include "run_light_behavior_ctrl_def.h"
#include "run_light_ctrl_timer.h"
#include "run_light_color_ctrl.h"
#include "run_light_action_ctrl_base.h"

const VOS_UINT32 LOOP_INFINITE = 0xFFFFFFFF;

enum class RunningStatus {
    RUNNING,
    FINISH,
    NOT_MOV
};

enum class IteratorType {
    INFINITE,
    FINITE
};

class RunLightActionIterator {
public:
    RunLightActionIterator() = default;
    ~RunLightActionIterator() = default;

    VOS_VOID      Init(RunLightColorCtrlBase *colorCtrl, RunLightCtrlTimer &timer);
    VOS_VOID      StartIterator(const LightBehaviorComp &behaviorComp);
    RunningStatus NextStep(VOS_UINT32 timerName);

private:
    VOS_VOID StartLoop();
    VOS_VOID NextLoop();

private:
    COMP_TIMER   m_itrTimer;

    VOS_UINT32    m_loopNum = 0;
    IteratorType  m_iteratorType = IteratorType::FINITE;
    RunningStatus m_iteratorStatus  = RunningStatus::FINISH;
    RunLightActionCtrlBase *m_actionCtrl = VOS_NULL_PTR;
    RunLightColorCtrlBase *m_colorCtrl = VOS_NULL_PTR;
};

#endif // RUN_LIGHT_ACTION_ITERATOR_H