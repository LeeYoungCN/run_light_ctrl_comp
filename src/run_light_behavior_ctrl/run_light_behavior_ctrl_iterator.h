#ifndef RUN_LIGHT_BEHAVIOR_CTRL_ITERATOR_H
#define RUN_LIGHT_BEHAVIOR_CTRL_ITERATOR_H
#include "vos_base.h"
#include "run_light_behavior_ctrl_public.h"
#include "run_light_behavior_ctrl_timer.h"

const VOS_UINT32 LOOP_INFINITE = 0xFFFFFFFF;

enum class RunningStatus {
    RUNNING,
    FINISH,
};

enum class IteratorType {
    INFINITE,
    FINITE
};

class RunLightBehaviorCtrlIterator {
public:
    RunLightBehaviorCtrlIterator() = default;
    ~RunLightBehaviorCtrlIterator();
    VOS_VOID Init(VOS_HANDEL_T handle, VOS_UINT32 lightIndex);
    VOS_VOID StartIterator(const LightBehaviorComp &behaviorComp);
    RunningStatus NextStep();
    RunningStatus GetCurrentStatus();

    virtual VOS_VOID SetColor(const LightColor lightColor) = 0;

private:
    VOS_VOID StartLoop();
    RunningStatus ActionNextStep();
    RunningStatus FlashNextStep();
    RunningStatus NoarmalNextStep();
    RunningStatus NextLoop();

private:
    VOS_HANDEL_T m_compHandle;
    VOS_UINT32   m_lightIndex;
    COMP_TIMER   m_compTimer;

    VOS_UINT32    m_counter         = 0;
    VOS_UINT32    m_loopNum         = 0;
    LightColor    m_lightColor      = LightColor::BLACK;
    LightAction   m_lightAction     = {ActionType::NORMAL, LightColor::BLACK, 0, 0, 0};
    IteratorType  m_iteratorType    = IteratorType::FINITE;
    RunningStatus m_actionStatus    = RunningStatus::FINISH;
    RunningStatus m_iteratorStatus  = RunningStatus::FINISH;
};

#endif // RUN_LIGHT_BEHAVIOR_CTRL_ITERATOR_H