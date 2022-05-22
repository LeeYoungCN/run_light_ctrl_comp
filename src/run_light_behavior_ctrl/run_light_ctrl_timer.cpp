#include "vos_base.h"
#include "vos_reltmrmsg.h"
#include "run_light_ctrl_timer.h"
#include "run_light_ctrl_comp_log.h"

VOS_VOID RunLightCtrlTimer::Init(VOS_HANDLE_T handle, VOS_UINT32 timerName)
{
    m_handle = handle;
    m_timerName = timerName;
}

VOS_UINT32 RunLightCtrlTimer::StartTimer(VOS_UINT32 delayTimeMs)
{
    StopTimer();
    m_timerDelay = delayTimeMs;
    VOS_UINT32 ret = VOS_ReltmrMsgStart(
        &m_timerId, m_handle, m_timerDelay,m_timerName, 0, 0, VOS_RELTIMER_LOOP);
    if (ret != VOS_OK) {
        RLC_LOG_ERROR("Start timer;Fail;Index=%u;,Ret=%u", m_timerName, ret);
    }
    return ret;
}

VOS_VOID RunLightCtrlTimer::StopTimer()
{
    if (m_timerId == VOS_NULL_PTR) {
        return;
    }
    VOS_UINT32 ret = VOS_ReltmrStop(&m_timerId);
    m_timerId = VOS_NULL_PTR;
    if (ret != VOS_OK) {
        RLC_LOG_ERROR("Stop timer;Fail;Index=%u;,Ret=%u", m_timerName, ret);
    }
}

VOS_BOOL RunLightCtrlTimer::IsMyTimer(VOS_UINT32 timerName)
{
    return (m_timerName == timerName ? VOS_TRUE : VOS_FALSE);
}
