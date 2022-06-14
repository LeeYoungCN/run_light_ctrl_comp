#include "run_light_behavior_ctrl_public_func.h"

VOS_BOOL IsValidAction(const LightAction &testAction)
{
    if ((testAction.actionType != ActionType::NORMAL) &&
        ((testAction.para1 == 0) || (testAction.para2 == 0))) {
        return VOS_FALSE;
    }
    return VOS_TRUE;
}

VOS_BOOL IsValidBehaviorComp(const LightBehaviorComp &testBehaviorComp)
{
    if ((!IsValidAction(testBehaviorComp.lightAction)) ||
        (testBehaviorComp.loopNum == 0)) {
        return VOS_FALSE;
    }
    return VOS_TRUE;
}

VOS_BOOL IsValidBehavior(const LightBehavior &testBehavior)
{
    for (VOS_UINT32 i = 0; i < testBehavior.componentNum; i++) {
        if ((!IsValidAction(testBehavior.componentArr[i].lightAction)) ||
            (testBehavior.componentArr[i].loopNum == 0)) {
            return VOS_FALSE;
        }
    }
    return VOS_TRUE;
}

