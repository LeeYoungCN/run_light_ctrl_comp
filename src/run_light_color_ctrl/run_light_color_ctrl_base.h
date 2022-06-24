#ifndef RUN_LIGHT_COLOR_CTRL_BASE_H
#define RUN_LIGHT_COLOR_CTRL_BASE_H

enum class ColorType : VOS_UINT32 {
    RED,
    GREEN,
    BLUE,
};

class RunLightColorCtrlBase {
public:
    RunLightColorCtrlBase();
    ~RunLightColorCtrlBase();

    virtual VOS_VOID SetColor(ColorType colorType, VOS_UINT32 luminance) = 0;
};

#endif // RUN_LIGHT_COLOR_CTRL_BASE_H
