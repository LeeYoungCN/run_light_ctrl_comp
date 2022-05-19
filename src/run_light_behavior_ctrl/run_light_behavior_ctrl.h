#ifndef LIGHT_RUNNING_CTRL_BASE_H
#define LIGHT_RUNNING_CTRL_BASE_H
#include "vos_base.h"
#include "run_light_behavior_ctrl_public.h"
#include "run_light_action_iterator.h"
#include "run_light_ctrl_timer.h"
#include "run_light_color_ctrl.h"

class RunLightBehaviorCtrl {
public:
    RunLightBehaviorCtrl() = default;
    virtual ~RunLightBehaviorCtrl() = default;
    explicit RunLightBehaviorCtrl(VOS_UINT16           lightId);
    explicit RunLightBehaviorCtrl(BreathLightPara      breathLightPara);
    explicit RunLightBehaviorCtrl(BreathLightGroupPara breathLightGroupPara);
    explicit RunLightBehaviorCtrl(NormalLightGroupPara normalLightGropuPara);

    VOS_VOID Init(VOS_HANDLE_T handle, VOS_UINT32 lightIndex);
    VOS_VOID SetBehavior(const LigtBehavior &newBehavior);
    VOS_VOID Run(VOS_UINT32 timerName);

private:
    VOS_UINT32   m_runStage = 0;
    LigtBehavior m_currBehavior = {0};
    RunLightActionIterator m_actionItr;

    RunLightCtrlTimer m_timer;
    RunLightColorCtrl m_colorCtrl;
};

#endif // LIGHT_RUNNING_CTRL_BASE_H
