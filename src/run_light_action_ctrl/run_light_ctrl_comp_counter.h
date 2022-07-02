#ifndef RUN_LIGHT_CTRL_COMP_COUNTER_H
#define RUN_LIGHT_CTRL_COMP_COUNTER_H
#include "vos_base.h"

class RunLightCtrlCompCounter {
public:
    RunLightCtrlCompCounter() = default;
    ~RunLightCtrlCompCounter() = default;
    VOS_VOID SetCountNum(VOS_UINT32 countNum);
    VOS_VOID Count();
    VOS_BOOL IsFinish();
private:
    VOS_UINT32 m_countNum = 0;
};

#endif //RUN_LIGHT_CTRL_COMP_COUNTER_H
