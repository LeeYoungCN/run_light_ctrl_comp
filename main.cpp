#include "light_running_ctrl_base.h"

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
    ActionGroupComp comp[] = {
        {normal, 1},
        {flash, 1},
    };

    static LigtActionGroup actionGroup = {
        comp,
        2
    };

    LightRunningCtrlBase c;
    LightRunningCtrlBase d;
    c.Init(1, 2);
    d.Init(1, 3);
    d.RefreshActionGroup(actionGroup);
    for (VOS_UINT32 i = 1; i < 10; i++) {
        cout << "i = " << i << endl;
        d.Run();
    }

    return 0;
}