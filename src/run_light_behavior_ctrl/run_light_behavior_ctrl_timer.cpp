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
    printf("start name = %u, time = %u\n", m_timerName, m_timerDelay);
}

VOS_VOID RunLightBehaviorCtrlTimer::StopTimer()
{
    printf("stop name = %u, time = %u\n", m_timerName, m_timerDelay);
}

VOS_UINT32 RunLightBehaviorCtrlTimer::IsMyTimer(VOS_UINT32 timerName)
{
    return (m_timerName == timerName ? VOS_OK : VOS_ERR);
}
