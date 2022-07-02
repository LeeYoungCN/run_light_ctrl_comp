#ifndef RUN_LIGHT_ACTION_BASE_H
#define RUN_LIGHT_ACTION_BASE_H
#include "vos_base.h"
#include "run_light_action_ctrl_def.h"
#include "run_light_color_ctrl_base.h"

class RunLightActionCtrlBase {
public:
    RunLightActionCtrlBase() = default;
    virtual ~RunLightActionCtrlBase();

    virtual VOS_UINT32   StartLoop(RunLightColorCtrlBase *colorCtrlInst) = 0;
    virtual ActionStatus NextStep() = 0;
    virtual VOS_BOOL     IsValidPara() = 0;

protected:
    virtual VOS_UINT32 Init(RunLightColorCtrlBase *colorCtrlInst);
    virtual VOS_VOID   SetColor(LightColor lightColor, VOS_UINT32 luminance);

private:
    RunLightColorCtrlBase *m_lightColorCtrlInst = VOS_NULL_PTR;
};

#endif // RUN_LIGHT_ACTION_BASE_H
