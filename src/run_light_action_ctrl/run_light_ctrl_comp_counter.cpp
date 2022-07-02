#include "run_light_ctrl_comp_counter.h"

VOS_VOID RunLightCtrlCompCounter::SetCountNum(VOS_UINT32 countNum)
{
    m_countNum = countNum;
}

VOS_VOID RunLightCtrlCompCounter::Count()
{
    if (m_countNum == 0) {
        return;
    }
    m_countNum--;
}

VOS_BOOL RunLightCtrlCompCounter::IsFinish()
{
    return (m_countNum == 0);
}
