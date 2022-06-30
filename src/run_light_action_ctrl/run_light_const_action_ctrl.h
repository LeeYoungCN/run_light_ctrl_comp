#ifndef RUN_LIGHT_CONST_ACTION_H
#define RUN_LIGHT_CONST_ACTION_H
#include "run_light_action_ctrl_base.h"
#include "run_light_action_ctrl_def.h"
#include "run_light_color_ctrl_base.h"

class RunLightConstActionCtrl : public RunLightActionCtrlBase {
public:
    RunLightConstActionCtrl(const LightAction &actionPara);
    virtual ~RunLightConstActionCtrl() = default;

    virtual VOS_UINT32   StartLoop(RunLightColorCtrlBase *colorCtrlInst) override;
    virtual ActionStatus NextStep() override;
    virtual VOS_BOOL     IsValidActionPara() override;
private:
    const LightAction m_actionPara;
    RunLightColorCtrlBase *m_colorCtrlInst = VOS_NULL_PTR;
};

#endif // RUN_LIGHT_CONST_ACTION_H
