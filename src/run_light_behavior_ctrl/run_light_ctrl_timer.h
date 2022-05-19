#ifndef RUN_LIGHT_BEHAVIOR_CTRL_TIMER_H
#define RUN_LIGHT_BEHAVIOR_CTRL_TIMER_H
#include "vos_base.h"
#include "vos_handle.h"
#include "vos_reltmrknl.h"

#define COMP_TIMER RunLightCtrlTimer

class RunLightCtrlTimer {
public:
    RunLightCtrlTimer() = default;
    ~RunLightCtrlTimer() = default;

    VOS_VOID   Init(VOS_HANDLE_T handle, VOS_UINT32 timerName);
    VOS_UINT32 StartTimer(VOS_UINT32 delayTimeMs);
    VOS_VOID   StopTimer();
    VOS_BOOL   IsMyTimer(VOS_UINT32 timerName);

private:
    VOS_HANDLE_T m_handle;
    VOS_RELTMR_T m_timerId;
    VOS_UINT32   m_timerName;
    VOS_UINT32   m_timerDelay;
};

#endif // RUN_LIGHT_BEHAVIOR_CTRL_TIMER_H