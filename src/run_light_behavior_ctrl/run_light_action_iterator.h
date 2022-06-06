#ifndef RUN_LIGHT_ACTION_ITERATOR_H
#define RUN_LIGHT_ACTION_ITERATOR_H
#include "vos_base.h"
#include "run_light_behavior_ctrl_def.h"
#include "run_light_ctrl_timer.h"
#include "run_light_color_ctrl.h"

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

    VOS_VOID      Init(RunLightColorCtrl &colorCtrl, RunLightCtrlTimer &timer);
    VOS_VOID      StartIterator(const LightBehaviorComp &behaviorComp);
    RunningStatus NextStep(VOS_UINT32 timerName);

private:
    VOS_VOID StartLoop();
    VOS_VOID ActionNextStep();
    VOS_VOID NextLoop();

    RunningStatus FlashNextStep();
    RunningStatus NoarmalNextStep();

private:
    COMP_TIMER   m_itrTimer;

    VOS_UINT32    m_counter         = 0;
    VOS_UINT32    m_loopNum         = 0;
    VOS_FLOAT     m_brightPct       = 0.0;
    VOS_FLOAT     m_btightDelta     = 0.0;

    LightColor    m_lightColor      = LightColor::BLACK;
    LightAction   m_lightAction     = {ActionType::NORMAL, LightColor::BLACK, 0, 0, 0};
    IteratorType  m_iteratorType    = IteratorType::FINITE;

    RunningStatus m_actionStatus    = RunningStatus::FINISH;
    RunningStatus m_iteratorStatus  = RunningStatus::FINISH;

    RunLightColorCtrl m_colorCtrl;
};

#endif // RUN_LIGHT_ACTION_ITERATOR_H