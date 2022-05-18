#include "vos_base.h"
#include "run_light_behavior_ctrl_timer.h"
#include "run_light_ctrl_comp_log.h"

VOS_VOID RunLightBehaviorCtrlTimer::Init(VOS_HANDEL_T handle, VOS_UINT32 timerName)
{
    m_handle = handle;
    m_timerName = timerName;
}

VOS_VOID RunLightBehaviorCtrlTimer::StartTimer(VOS_UINT32 delayTimeMs)
{
    StopTimer();
    m_timerDelay = delayTimeMs;
    RCL_LOG_EVENT("start name = %u, time = %u\n", m_timerName, m_timerDelay);
}

VOS_VOID RunLightBehaviorCtrlTimer::StopTimer()
{
    RCL_LOG_EVENT("stop name = %u, time = %u\n", m_timerName, m_timerDelay);
}

VOS_BOOL RunLightBehaviorCtrlTimer::IsMyTimer(VOS_UINT32 timerName)
{
    return (m_timerName == timerName ? VOS_TRUE : VOS_FALSE);
}
