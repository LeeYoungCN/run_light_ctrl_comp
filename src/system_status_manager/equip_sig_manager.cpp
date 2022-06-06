#include "equip_sig_manager.h"


EquipSigManager::EquipSigManager(VOS_UINT32 equipId, EquipSigCfg equipSigCfg)
    : m_equipId(equipId),
      m_typeId(equipSigCfg.typeId),
      m_setSigInfo(equipSigCfg.setSigInfo),
      m_setSigNum(equipSigCfg.setSigNum),
      m_almSigInfo(equipSigCfg.almSigInfo),
      m_almSigNum(equipSigCfg.almSigNum)
{}

VOS_VOID EquipSigManager::AddEquip(VOS_UINT16 typeId, VOS_UINT16 equipId, VOS_UINT16 phySlot)
{
    if (IsRegReport()) {
        return;
    }
    if ((m_typeId != typeId) || (m_equipId != equipId)) {
        return;
    }
    m_phySlot = phySlot;
    m_isCreated = VOS_TRUE;

    // 注册信号主动上报
    m_isRegRport = VOS_TRUE;
}

VOS_VOID EquipSigManager::DelEquip(VOS_UINT16 typeId, VOS_UINT16 equipId)
{
    if ((m_typeId != typeId) || (m_equipId != equipId)) {
        return;
    }
    m_isCreated = VOS_FALSE;
}

VOS_UINT16 EquipSigManager::GetTypeId() const
{
    return m_typeId;
}

VOS_UINT16 EquipSigManager::GetEquipId() const
{
    return m_equipId;
}

VOS_BOOL EquipSigManager::IsNeedRegAlmReport() const
{
    return ((m_almSigInfo != VOS_NULL_PTR) && (m_almSigNum > 0));
}

VOS_UINT16 EquipSigManager::GetSetSigVal(VOS_UINT16 setSigId, VOS_UINT32 &sigVal) const
{
    if (!IsCreated()) {
        return VOS_ERR;
    }
    VOS_UINT32 sigIdx = GetSigIdIndex(setSigId, m_setSigInfo, m_setSigNum);
    if (sigIdx >= m_setSigNum) {
        return VOS_ERR;
    }
    sigVal = m_setSigInfo->sigVal.uintVal;
    return VOS_OK;
}

VOS_UINT16 EquipSigManager::GetSetSigVal(VOS_UINT16 setSigId, VOS_INT32  &sigVal) const
{
    if (!IsCreated()) {
        return VOS_ERR;
    }

    VOS_UINT32 setSigIdx = GetSigIdIndex(setSigId, m_setSigInfo, m_setSigNum);
    if (setSigIdx >= m_setSigNum) {
        return VOS_ERR;
    }
    sigVal = m_setSigInfo[setSigIdx].sigVal.sintVal;
    return VOS_OK;
}

VOS_UINT16 EquipSigManager::GetSetSigVal(VOS_UINT16 setSigId, VOS_FLOAT &sigVal) const
{
    if (!IsCreated()) {
        return VOS_ERR;
    }
    VOS_UINT32 setSigIdx = GetSigIdIndex(setSigId, m_setSigInfo, m_setSigNum);
    if (setSigIdx >= m_setSigNum) {
        return VOS_ERR;
    }
    sigVal = m_setSigInfo[setSigIdx].sigVal.floatVal;
    return VOS_OK;
}

VOS_UINT16 EquipSigManager::GetAlmSigVal(VOS_UINT16 almSigId, VOS_UINT32 &sigVal) const
{
    if (!IsCreated()) {
        return VOS_ERR;
    }
    VOS_UINT32 almSigIdx = GetSigIdIndex(almSigId, m_almSigInfo, m_almSigNum);
    if (almSigIdx >= m_almSigNum) {
        return VOS_ERR;
    }
    sigVal = m_almSigInfo[almSigIdx].sigVal.uintVal;
    return VOS_OK;
}

VOS_UINT16 EquipSigManager::RefreshSetSigVal(VOS_UINT16 setSigId, VOS_UINT8 *sigVal, VOS_UINT32 sigSize)
{
    return VOS_OK;
}

VOS_UINT16 EquipSigManager::RefreshAlmSigVal(VOS_UINT16 almSigId, VOS_UINT32 sigVal)
{
    VOS_UINT32 almSigIdIdx = GetSigIdIndex(almSigId, m_almSigInfo, m_almSigNum);
    if (almSigIdIdx >= m_almSigNum) {
        return VOS_ERR;
    }

    m_almSigInfo[almSigIdIdx].sigVal.uintVal = sigVal;
    return VOS_OK;
}

VOS_UINT16 EquipSigManager::IsMySigId(VOS_UINT16 typeId, VOS_UINT16 equipId, VOS_UINT16 sigId)
{
    if ((m_typeId != typeId) || (m_equipId != equipId)) {
        return VOS_ERR;
    }

    if ((GetSigIdIndex(sigId, m_setSigInfo, m_setSigNum) >= m_setSigNum) &&
        (GetSigIdIndex(sigId, m_almSigInfo, m_almSigNum) >= m_almSigNum)) {
        return VOS_ERR;
    }

    return VOS_OK;
}

VOS_UINT32 EquipSigManager::GetSigIdIndex(VOS_UINT16 sigId, SigInfo *sigInfo, VOS_UINT32 sigNum) const
{
    VOS_UINT32 sigIdx = 0;
    for (;sigIdx < sigNum; ++sigIdx) {
        if (sigInfo->sigId != sigId) {
            continue;
        }
        break;
    }
    return sigIdx;
}

VOS_BOOL EquipSigManager::IsCreated() const
{
    return m_isCreated;
}

VOS_BOOL EquipSigManager::IsRegReport() const
{
    return m_isRegRport;
}
