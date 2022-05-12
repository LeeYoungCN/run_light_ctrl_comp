#ifndef LIGHT_RUNNING_CTRL_BASE_H
#define LIGHT_RUNNING_CTRL_BASE_H
#include "vos_base.h"
#include "run_light_behavior_ctrl_public.h"
#include "run_light_behavior_ctrl_iterator.h"

class RunLightBehaviorCtrlBase : protected RunLightBehaviorCtrlIterator {
public:
    RunLightBehaviorCtrlBase();
    virtual ~RunLightBehaviorCtrlBase();

    VOS_VOID Init(VOS_HANDEL_T handle, VOS_UINT32 lightIndex);
    VOS_VOID SetBehavior(const LigtBehavior &newBehavior);
    VOS_VOID SetColor(const LightColor lightColor) override;
    VOS_VOID Run();
private:
    VOS_UINT32   m_runStage = 0;
    LigtBehavior m_currBehavior = {0};
};

#endif // LIGHT_RUNNING_CTRL_BASE_H
