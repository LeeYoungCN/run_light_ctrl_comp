#ifndef RUN_LIGHT_COLOR_CTRL_DEF_H
#define RUN_LIGHT_COLOR_CTRL_DEF_H
#include "vos_base.h"

enum class LightColor {
    RED,    // 红
    GREEN,  // 绿
    BLUE,   // 蓝
    YELLOW, // 黄(红+绿)
    PURPLE, // 紫(红+蓝)
    CYAN,   // 青(绿+蓝)
    WHITE,  // 白(红+绿+蓝)
    BLACK,  // 黑(无)
};

const VOS_UINT32 MAX_BRIGHT_PERCENT_FLOAT = 100.00;
const VOS_UINT32 MAX_LUMINANCE   = 100;

enum class LightType {
    NORMAL_LIGHT,
    BREATH_LIGHT,
    NORMAL_LIGHT_GROUP,
    BREATH_LIGHT_GROUP
};

enum class LightStatus {
    ON,
    OFF
};

struct NormalLightGroupPara {
    VOS_UINT16 redId;
    VOS_UINT16 greenId;
    VOS_UINT16 blueId;
};

struct BreathLightPara {
    VOS_UINT16 gptId;
    VOS_UINT8  gptchl;
    VOS_UINT32 maxCompare;
};

struct BreathLightGroupPara {
    BreathLightPara redLight;
    BreathLightPara greenLight;
    BreathLightPara blueLight;
};

#endif // RUN_LIGHT_COLOR_CTRL_DEF_H
