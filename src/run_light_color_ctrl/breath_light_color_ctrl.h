#ifndef BREATH_LIGHT_COLOR_CTRL_H
#define BREATH_LIGHT_COLOR_CTRL_H

#include "run_light_color_ctrl_base.h"

class BreathLightColorCtrl : public RunLightColorCtrlBase {
public:
    explicit BreathLightColorCtrl(const BreathLightPara &lightPara);
    ~BreathLightColorCtrl() = default;

    VOS_BOOL Init(VOS_UINT32 lightIdex) override;
    VOS_VOID SetColor(LightColor colorType, VOS_UINT32 luminance = MAX_LUMINANCE) override;
private:
    VOS_UINT32 InitPwmPara();
    const BreathLightPara m_lightPara;
};

#endif // BREATH_LIGHT_COLOR_CTRL_H
