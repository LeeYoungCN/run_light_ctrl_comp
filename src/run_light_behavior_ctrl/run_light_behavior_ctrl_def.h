#ifndef RUN_LIGHT_BEHAVIOR_CTRL_DEF_H
#define RUN_LIGHT_BEHAVIOR_CTRL_DEF_H
#include "vos_base.h"

#ifndef U16_ITEM_OF
#define U16_ITEM_OF(arr) static_cast<VOS_UINT32>(sizeof(arr) / sizeof(arr[0]))
#endif

// 颜色相关
const VOS_FLOAT MAX_BRIGHT_PERCENT = 100.0;

enum class LightType {
    NORMAL_LIGHT,
    BREATH_LIGHT,
    NORMAL_LIGHT_GROUP,
    BREATH_LIGHT_GROUP
};

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

// 动作相关
enum class ActionType {
    NORMAL,
    FLASH,
    BREATH_LINE,
    BREATH_CURVE,
};

struct LightAction {
    ActionType actionType;
    LightColor lightColor;
    VOS_FLOAT brightPct;
    VOS_UINT32 delayTime;
    VOS_UINT32 para1;
    VOS_UINT32 para2;
};

struct LightBehaviorComp {
    LightAction lightAction; // 动作
    VOS_UINT32  loopNum;     // 循环次数
};

struct LightBehavior {
    LightBehaviorComp *componentArr;
    VOS_UINT32         componentNum;
};

#endif // RUN_LIGHT_BEHAVIOR_CTRL_DEF_H
