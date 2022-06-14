#ifndef RUN_LIGHT_COLOR_CTRL_H
#define RUN_LIGHT_COLOR_CTRL_H
#include "vos_base.h"
#include "run_light_behavior_ctrl_def.h"

class RunLightColorCtrl {
public:
    RunLightColorCtrl() = default;
    ~RunLightColorCtrl() = default;

    explicit RunLightColorCtrl(VOS_UINT16           lightId);
    explicit RunLightColorCtrl(BreathLightPara      breathLightPara);
    explicit RunLightColorCtrl(BreathLightGroupPara breathLightGroupPara);
    explicit RunLightColorCtrl(NormalLightGroupPara normalLightGropuPara);
    VOS_VOID Init(VOS_UINT32 lightIndex);
    VOS_VOID SetColor(LightColor lightColor, VOS_UINT32 brightPct = MAX_BRIGHT_PERCENT);

private:
    VOS_VOID CtrlNormalLightColor(LightColor lightColor);
    VOS_VOID CtrlNormalLightGroupColor(LightColor lightColor);
    VOS_VOID CtrlNormalLightStatus(VOS_UINT16 lightId, LightStatus status);

    VOS_VOID CtrlBreathLightColor(LightColor lightColor, VOS_UINT32 brightPct);
    VOS_VOID CtrlBreathLightGroupColor(LightColor lightColor, VOS_UINT32 brightPct);
    VOS_VOID CtrlBreathLightStatus(BreathLightPara lightPara, LightStatus LightStatus, VOS_UINT32 brightPct);

    LightType            m_lightType = LightType::NORMAL_LIGHT;
    VOS_UINT32           m_lightIndex = 0;
    NormalLightGroupPara m_normalLightGropuPara {0, 0, 0};
    BreathLightGroupPara m_breathLightGroupPara {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
};

#endif // RUN_LIGHT_COLOR_CTRL_H
