#include "vos_base.h"
#include "run_light_behavior_ctrl_timer.h"

VOS_VOID RunLightBehaviorCtrlTimer::Init(VOS_HANDEL_T handle, VOS_UINT32 timerName)
{
    m_handle = handle;
    m_timerName = timerName;
}

VOS_VOID RunLightBehaviorCtrlTimer::StartTimer(VOS_UINT32 delayTimeMs)
{

}

VOS_VOID RunLightBehaviorCtrlTimer::StopTimer()
{

}

VOS_UINT32 RunLightBehaviorCtrlTimer::IsMyTimer(VOS_UINT32 timerName)
{
    return (m_timerName == timerName ? VOS_OK : VOS_ERR);
}
