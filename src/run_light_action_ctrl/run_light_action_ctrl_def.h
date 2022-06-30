#ifndef RUN_LIGHT_ACTION_DEF_H
#define RUN_LIGHT_ACTION_DEF_H
#include "vos_base.h"
#include "run_light_color_ctrl_def.h"

enum class ActionStatus {
    RUNNING,
    FINISH,
};

// 动作相关
enum class ActionType {
    CONST,
    FLASH,
    BREATH,
};

struct LightAction {
    ActionType actionType;
    LightColor  lightColor;
    VOS_UINT32 luminace;
    VOS_UINT32 delayTime;
    VOS_UINT32 para1;
    VOS_UINT32 para2;
};

#endif // RUN_LIGHT_ACTION_DEF_H
