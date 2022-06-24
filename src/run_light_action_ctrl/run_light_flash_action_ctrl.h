#ifndef RUN_LIGHT_FLASH_ACTION_H
#define RUN_LIGHT_FLASH_ACTION_H
#include "run_light_action_ctrl_base.h"
#include "run_light_action_ctrl_def.h"

class RunLightFlashActionCtrl : public RunLightActionCtrlBase {
public:
    RunLightFlashActionCtrl(const LightActionPara &actionPara);
    virtual ~RunLightFlashActionCtrl() = default;

    virtual VOS_UINT32   StartLoop();
    virtual ActionStatus NextStep();
private:
    const LightActionPara m_actionPara;
};

#endif // RUN_LIGHT_FLASH_ACTION_H
