#ifndef RUN_LIGHT_BREATH_ACTION_CTRL_H
#define RUN_LIGHT_BREATH_ACTION_CTRL_H
#include "run_light_action_ctrl_base.h"
#include "run_light_action_ctrl_def.h"
#include "run_light_ctrl_comp_counter.h"

enum class BreathOperate : VOS_UINT32 {
    ADD,
    SUB
};

class RunLightBreathActionCtrl : public RunLightActionCtrlBase {
public:
    RunLightBreathActionCtrl(const LightAction &actionPara);
    virtual ~RunLightBreathActionCtrl() = default;

    virtual VOS_UINT32   StartAction(RunLightColorCtrlBase *colorCtrlInst) override;
    virtual ActionStatus NextStep() override;
    virtual VOS_BOOL     IsValidPara() override;
protected:
    virtual VOS_VOID    RefreshLightLuminace();
private:
    const LightAction       m_actionPara;
    RunLightCtrlCompCounter m_counter;
    LightColor m_lightColor = LightColor::BLACK;
    VOS_UINT32 m_lightLuminance = 0;
    VOS_UINT32 m_luminanceDelta = 0;
    BreathOperate m_operate = BreathOperate::ADD;
};

#endif // RUN_LIGHT_BREATH_ACTION_CTRL_H