#ifndef RUN_LIGHT_CTRL_COMP_COUNTER_H
#define RUN_LIGHT_CTRL_COMP_COUNTER_H
#include "vos_base.h"

class RunLightCtrlCompCounter {
public:
    RunLightCtrlCompCounter() = default;
    ~RunLightCtrlCompCounter() = default;
    VOS_VOID StartCount(VOS_UINT32 countNum);
    VOS_BOOL IsFinish();
private:
    VOS_UINT32 m_cntNum = 0;
};

#endif //RUN_LIGHT_CTRL_COMP_COUNTER_H
