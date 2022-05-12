#ifndef LIGHT_RUNNING_CTRL_BASE_H
#define LIGHT_RUNNING_CTRL_BASE_H
#include "vos_base.h"
#include "light_running_ctrl_public_def.h"
#include "light_running_ctrl_iterator.h"

class LightRunningCtrlBase : protected LightRunningCtrlIterator {
public:
    LightRunningCtrlBase();
    virtual ~LightRunningCtrlBase();

    VOS_VOID Init(VOS_HANDEL_T handle, VOS_UINT32 lightIndex);
    VOS_VOID RefreshActionGroup(const LigtActionGroup &LightActionGroup);
    VOS_VOID SetColor(const LightColor lightColor) override;
    VOS_VOID SetAction(const LightAction &lightAction);
    VOS_VOID SetAction(const ActionGroupComp &actionComp);
    VOS_VOID Run();
private:
    VOS_UINT32   m_runStage;
    LigtActionGroup   m_currActionGroup;
};

#endif // LIGHT_RUNNING_CTRL_BASE_H
