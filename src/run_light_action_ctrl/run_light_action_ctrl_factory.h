#ifndef RUN_LIGHT_ACTION_FACTORY_H
#define RUN_LIGHT_ACTION_FACTORY_H
#include "vos_base.h"
#include "run_light_action_ctrl_base.h"

class RunLightActionCtrlFactory {
public:
    static RunLightActionCtrlFactory &GetInstance();
private:
    RunLightActionCtrlFactory() = default;
    ~RunLightActionCtrlFactory() = default;
public:
    RunLightActionCtrlBase *CreateRunLightAction(const LightAction &actionPara);
};

#endif // RUN_LIGHT_ACTION_FACTORY_H
