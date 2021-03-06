#include "run_light_action_ctrl_factory.h"
#include "run_light_action_ctrl_def.h"
#include "run_light_const_action_ctrl.h"
#include "run_light_flash_action_ctrl.h"
#include "run_light_breath_action_ctrl.h"

RunLightActionCtrlFactory &RunLightActionCtrlFactory::GetInstance()
{
    static RunLightActionCtrlFactory runLightActionCtrlFactoryInst;
    return runLightActionCtrlFactoryInst;
}

RunLightActionCtrlBase *RunLightActionCtrlFactory::CreateRunLightAction(const LightAction &actionPara)
{
    RunLightActionCtrlBase *ret = VOS_NULL_PTR;
    switch (actionPara.actionType) {
        case ActionType::CONST: {
            ret =  new RunLightConstActionCtrl(actionPara);
            break;
        }
        case ActionType::FLASH: {
            ret =  new RunLightFlashActionCtrl(actionPara);
            break;
        }
        case ActionType::BREATH: {
            ret = new RunLightBreathActionCtrl(actionPara);
            break;
        }
        default:
            break;
    }
    return ret;
}
