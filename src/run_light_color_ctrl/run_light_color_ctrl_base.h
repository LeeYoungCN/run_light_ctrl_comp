#ifndef RUN_LIGHT_COLOR_CTRL_BASE_H
#define RUN_LIGHT_COLOR_CTRL_BASE_H
#include "run_light_color_ctrl_def.h"
class RunLightColorCtrlBase {
public:
    RunLightColorCtrlBase();
    ~RunLightColorCtrlBase();

    virtual VOS_VOID SetColor(LightColor colorType, VOS_UINT32 luminance = 100) = 0;
};

#endif // RUN_LIGHT_COLOR_CTRL_BASE_H
