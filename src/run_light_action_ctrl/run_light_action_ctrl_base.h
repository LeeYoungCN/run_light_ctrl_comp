#ifndef RUN_LIGHT_ACTION_BASE_H
#define RUN_LIGHT_ACTION_BASE_H
#include "vos_base.h"
#include "run_light_action_ctrl_def.h"

class RunLightActionCtrlBase {
public:
    RunLightActionCtrlBase() = default;
    virtual ~RunLightActionCtrlBase() = default;

    virtual VOS_UINT32   StartLoop();
    virtual ActionStatus NextStep();
};

#endif // RUN_LIGHT_ACTION_BASE_H
