#include "run_light_behavior_ctrl_base.h"

int main()
{
    LightAction normal = {
        ActionType::NORMAL,
        LightColor::RED,
        1000,
        0,
        0
    };
    LightAction flash = {
        ActionType::FLASH,
        LightColor::GREEN,
        100,
        2,
        3,
    };
    LightBehaviorComp comp[] = {
        {normal, 1},
        {flash, 1},
    };

    static LigtBehavior actionGroup = {
        comp,
        2
    };

    RunLightBehaviorCtrlBase c;
    RunLightBehaviorCtrlBase d;
    c.Init(1, 2);
    d.Init(1, 3);
    d.SetBehavior(actionGroup);
    for (VOS_UINT32 i = 1; i < 10; i++) {
        cout << "i = " << i << endl;
        d.Run();
    }

    return 0;
}