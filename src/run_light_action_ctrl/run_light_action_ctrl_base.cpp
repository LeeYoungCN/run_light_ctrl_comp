#include "run_light_action_ctrl_base.h"

RunLightActionCtrlBase::~RunLightActionCtrlBase()
{
    if (m_lightColorCtrlInst != VOS_NULL_PTR) {
        m_lightColorCtrlInst = VOS_NULL_PTR;
    }
}

VOS_VOID RunLightActionCtrlBase::StopAction()
{
    ;
}


VOS_UINT32 RunLightActionCtrlBase::Init(RunLightColorCtrlBase *colorCtrlInst)
{
    if ((colorCtrlInst == VOS_NULL_PTR) || (!IsValidPara())) {
        return VOS_ERR;
    }
    m_lightColorCtrlInst = colorCtrlInst;
    return VOS_OK;
}

VOS_VOID RunLightActionCtrlBase::SetColor(LightColor lightColor, VOS_UINT32 luminance)
{
    if (m_lightColorCtrlInst == VOS_NULL_PTR) {
        return;
    }
    m_lightColorCtrlInst->SetColor(lightColor, luminance);
}
