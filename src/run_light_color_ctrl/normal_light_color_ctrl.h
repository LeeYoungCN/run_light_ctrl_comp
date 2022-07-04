#ifndef NORMAL_LIGHT_COLOR_CTRL_H
#define NORMAL_LIGHT_COLOR_CTRL_H
#include "run_light_action_ctrl_base.h"

class NormalLightColorCtrl : public RunLightColorCtrlBase {
public:
    explicit NormalLightColorCtrl(VOS_UINT16 lightId);
    ~NormalLightColorCtrl() = default;

    virtual VOS_BOOL Init(VOS_UINT32 lightIndex) override;
    virtual VOS_VOID SetColor(LightColor colorType, VOS_UINT32 luminance = MAX_LUMINANCE) override;
private:
    VOS_VOID CtrlLightStatus(LightStatus status);

    VOS_UINT16 m_lightId;
    VOS_UINT32 m_lightIndex = 0;
};

#endif // NORMAL_LIGHT_COLOR_CTRL_H
