#ifndef RUN_LIGHT_BEHAVIOR_CTRL_PUBLIC_FUNC_H
#define RUN_LIGHT_BEHAVIOR_CTRL_PUBLIC_FUNC_H
#include "run_light_behavior_ctrl_def.h"

VOS_BOOL IsValidAction(const LightAction &testAction);
VOS_BOOL IsValidBehaviorComp(const LightBehaviorComp &testBehaviorComp);
VOS_BOOL IsValidBehavior(const LightBehavior &testBehavior);

#endif // RUN_LIGHT_BEHAVIOR_CTRL_PUBLIC_FUNC_H
