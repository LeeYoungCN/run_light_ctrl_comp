#ifndef RUN_LIGHT_BEHAVIOR_CTRL_TIMER_H
#define RUN_LIGHT_BEHAVIOR_CTRL_TIMER_H
#include "vos_base.h"

#define COMP_TIMER RunLightBehaviorCtrlTimer

class RunLightBehaviorCtrlTimer {
public:
    RunLightBehaviorCtrlTimer() = default;
    ~RunLightBehaviorCtrlTimer() = default;

    VOS_VOID Init(VOS_HANDEL_T handle, VOS_UINT32 timerName);
    VOS_VOID StartTimer(VOS_UINT32 delayTimeMs);
    VOS_VOID StopTimer();
    VOS_UINT32 IsMyTimer(VOS_UINT32 timerName);
private:
    VOS_HANDEL_T m_handle;
    VOS_UINT32 m_timerId;
    VOS_UINT32 m_timerName;
    VOS_UINT32 m_timerDelay;
};

#endif // RUN_LIGHT_BEHAVIOR_CTRL_TIMER_H