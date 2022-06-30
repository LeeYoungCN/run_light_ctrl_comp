#ifndef RUN_LIGHT_FLASH_ACTION_H
#define RUN_LIGHT_FLASH_ACTION_H
#include "run_light_action_ctrl_base.h"
#include "run_light_action_ctrl_def.h"
#include "run_light_ctrl_comp_counter.h"

class RunLightFlashActionCtrl : public RunLightActionCtrlBase {
public:
    RunLightFlashActionCtrl(const LightAction &actionPara);
    virtual ~RunLightFlashActionCtrl() = default;

    virtual VOS_UINT32   StartLoop(RunLightColorCtrlBase *colorCtrlInst) override;
    virtual ActionStatus NextStep() override;
    virtual VOS_BOOL     IsValidActionPara() override;
private:
    const LightAction       m_actionPara;
    RunLightColorCtrlBase  *m_colorCtrlInst = VOS_NULL_PTR;
    RunLightCtrlCompCounter m_counter;
    LightColor m_lightColor = LightColor::BLACK;
};

#endif // RUN_LIGHT_FLASH_ACTION_H
