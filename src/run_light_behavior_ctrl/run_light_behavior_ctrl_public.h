#ifndef RUN_LIGHT_BEHAVIOR_CTRL_PUBLIC_H
#define RUN_LIGHT_BEHAVIOR_CTRL_PUBLIC_H
#include "vos_base.h"

enum class LightType {
    NORMAL_LIGHT,
    BREATH_LIGHT,
    NORMAL_LIGHT_GROUP,
    BREATH_LIGHT_GROUP
};

enum class LightColor {
    RED,
    GREEN,
    BLUE,
    YELLOW, // 黄色(红+绿)
    PURPLE, // 紫色(红+蓝)
    CYAN,   // 青色(绿+蓝)
    WHITE,  // 白色(红+绿+蓝)
    BLACK,  // 黑色(无)
};

enum class ActionType {
    NORMAL,
    FLASH,
    BREATH,
};

struct LightAction {
    ActionType actionType;
    LightColor lightColor;
    VOS_UINT32 delayTime;
    VOS_UINT32 para1;
    VOS_UINT32 para2;
};

struct LightBehaviorComp {
    LightAction lightAction;  // 动作
    VOS_UINT32  loopNum;     // 循环次数
};

struct LigtBehavior {
    LightBehaviorComp *componentArr;
    VOS_UINT32         componentNum;
};

#endif // RUN_LIGHT_BEHAVIOR_CTRL_PUBLIC_H