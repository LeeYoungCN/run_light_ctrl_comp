#ifndef RUN_LIGHT_BEHAVIOR_CTRL_DEF_H
#define RUN_LIGHT_BEHAVIOR_CTRL_DEF_H
#include "vos_base.h"
#include "run_light_action_ctrl_def.h"
#include "run_light_color_ctrl_def.h"

#ifndef U16_ITEM_OF
#define U16_ITEM_OF(arr) static_cast<VOS_UINT32>(sizeof(arr) / sizeof(arr[0]))
#endif

struct LightBehaviorComp {
    LightAction lightAction; // 动作
    VOS_UINT32  loopNum;     // 循环次数
};

struct LightBehavior {
    LightBehaviorComp *componentArr;
    VOS_UINT32         componentNum;
};

#endif // RUN_LIGHT_BEHAVIOR_CTRL_DEF_H
