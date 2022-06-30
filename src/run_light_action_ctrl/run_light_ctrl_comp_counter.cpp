#include "run_light_ctrl_comp_counter.h"

VOS_VOID RunLightCtrlCompCounter::StartCount(VOS_UINT32 countNum)
{
    m_cntNum = countNum;
}

VOS_BOOL RunLightCtrlCompCounter::IsFinish()
{
    if (m_cntNum > 0) {
        m_cntNum--;
    }
    return (m_cntNum == 0);
}
