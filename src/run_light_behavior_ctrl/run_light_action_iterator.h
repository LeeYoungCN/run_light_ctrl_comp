#ifndef RUN_LIGHT_ACTION_ITERATOR_H
#define RUN_LIGHT_ACTION_ITERATOR_H
#include "vos_base.h"
#include "run_light_behavior_ctrl_public.h"
#include "run_light_behavior_ctrl_timer.h"
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
    explicit RunLightActionIterator(VOS_UINT16           lightId);
    explicit RunLightActionIterator(BreathLightPara      breathLightPara);
    explicit RunLightActionIterator(BreathLightGroupPara breathLightGroupPara);
    explicit RunLightActionIterator(NormalLightGroupPara normalLightGropuPara);

    VOS_VOID Init(VOS_HANDEL_T handle, VOS_UINT32 lightIndex);
    VOS_VOID StartIterator(const LightBehaviorComp &behaviorComp);
    RunningStatus NextStep(VOS_UINT32 timerName);

private:
    VOS_VOID StartLoop();
    VOS_VOID ActionNextStep();
    VOS_VOID NextLoop();

    RunningStatus FlashNextStep();
    RunningStatus NoarmalNextStep();

private:
    COMP_TIMER   m_itrTimer;

    VOS_UINT32    m_flashCnt        = 0;
    VOS_UINT32    m_loopNum         = 0;

    LightColor    m_lightColor      = LightColor::BLACK;
    LightAction   m_lightAction     = {ActionType::NORMAL, LightColor::BLACK, 0, 0, 0};
    IteratorType  m_iteratorType    = IteratorType::FINITE;

    RunningStatus m_actionStatus    = RunningStatus::FINISH;
    RunningStatus m_iteratorStatus  = RunningStatus::FINISH;

    RunLightColorCtrl m_runLightColorCtrl;
};

#endif // RUN_LIGHT_ACTION_ITERATOR_H