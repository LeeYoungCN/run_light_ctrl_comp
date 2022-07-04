#ifndef RUN_LIGHT_COLOR_CTRL_BASE_H
#define RUN_LIGHT_COLOR_CTRL_BASE_H
#include "run_light_color_ctrl_def.h"
class RunLightColorCtrlBase {
public:
    RunLightColorCtrlBase() = default;
    ~RunLightColorCtrlBase() = default;
    virtual VOS_BOOL Init(VOS_UINT32 lightIndex) = 0;
    virtual VOS_VOID SetColor(LightColor colorType, VOS_UINT32 luminance = MAX_LUMINANCE) = 0;
};

#endif // RUN_LIGHT_COLOR_CTRL_BASE_H
