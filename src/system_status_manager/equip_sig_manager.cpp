#include "equip_sig_manager.h"


EquipSigManager::EquipSigManager(VOS_UINT32 equipId, EquipSigCfg equipSigCfg)
    : m_equipId(equipId),
      m_typeId(equipSigCfg.typeId),
      m_sigInfoArr(equipSigCfg.sigInfoArr),
      m_sigInfoNum(equipSigCfg.sigInfoNum),
      m_almInfoArr(equipSigCfg.almInfoArr),
      m_almInfoNum(equipSigCfg.almInfoNum)
{}

VOS_VOID EquipSigManager::AddEquip()
{
    if (IsRegReport()) {
        return;
    }
    m_isCreated = VOS_TRUE;

    // 注册信号主动上报
    m_isRegRport = VOS_TRUE;
}

VOS_VOID EquipSigManager::DelEquip()
{
    m_isCreated = VOS_FALSE;
}

VOS_BOOL EquipSigManager::IsNeedRegAlmReport() const
{
    return ((m_almInfoArr != VOS_NULL_PTR) && (m_almInfoNum > 0));
}

VOS_UINT16 EquipSigManager::GetSignalValue(VOS_UINT16 sigId, VOS_UINT32 &sigVal) const
{
    if (!IsCreated()) {
        return VOS_ERR;
    }
    VOS_UINT32 sigIdx = FindSigIdIndex(sigId);
    if (sigIdx >= m_sigInfoNum) {
        return VOS_ERR;
    }
    sigVal = m_sigInfoArr->sigVal.uintVal;
    return VOS_OK;
}

VOS_UINT16 EquipSigManager::GetSignalValue(VOS_UINT16 sigId, VOS_INT32  &sigVal) const
{
    if (!IsCreated()) {
        return VOS_ERR;
    }

    VOS_UINT32 setSigIdx = FindSigIdIndex(sigId);
    if (setSigIdx >= m_sigInfoNum) {
        return VOS_ERR;
    }
    sigVal = m_sigInfoArr[setSigIdx].sigVal.sintVal;
    return VOS_OK;
}

VOS_UINT16 EquipSigManager::GetSignalValue(VOS_UINT16 sigId, VOS_FLOAT &sigVal) const
{
    if (!IsCreated()) {
        return VOS_ERR;
    }
    VOS_UINT32 setSigIdx = FindSigIdIndex(sigId);
    if (setSigIdx >= m_sigInfoNum) {
        return VOS_ERR;
    }
    sigVal = m_sigInfoArr[setSigIdx].sigVal.floatVal;
    return VOS_OK;
}

VOS_UINT16 EquipSigManager::GetAlarmStatusl(VOS_UINT16 almId, VOS_UINT32 &status) const
{
    if (!IsCreated()) {
        return VOS_ERR;
    }
    VOS_UINT32 almSigIdx = FindAlmIdIndex(almId);
    if (almSigIdx >= m_almInfoNum) {
        return VOS_ERR;
    }
    status = m_almInfoArr[almSigIdx].almStatus;
    return VOS_OK;
}

VOS_UINT16 EquipSigManager::RefreshSignalValue(VOS_UINT16 sigId, VOS_UINT32 sigVal)
{

    return VOS_OK;
}

VOS_UINT16 EquipSigManager::RefreshAlarmStatus(VOS_UINT16 almId, VOS_UINT32 status)
{
    VOS_UINT32 almSigIdIdx = FindAlmIdIndex(almId);
    if (almSigIdIdx >= m_almInfoNum) {
        return VOS_ERR;
    }

    m_almInfoArr[almSigIdIdx].almStatus = status;
    return VOS_OK;
}

VOS_BOOL EquipSigManager::IsMyEqupId(VOS_UINT16 equipId) const
{
    return (equipId == m_equipId);
}

VOS_UINT32 EquipSigManager::FindSigIdIndex(VOS_UINT16 sigId) const
{
    VOS_UINT32 sigIdx = 0;
    for (;sigIdx < m_sigInfoNum; ++sigIdx) {
        if (m_sigInfoArr[sigIdx].sigId == sigId) {
            return sigIdx;
        }
    }
    return sigIdx;
}

VOS_UINT32 EquipSigManager::FindAlmIdIndex(VOS_UINT16 almId) const
{
    VOS_UINT32 almIdIdx = 0;
    for (;almIdIdx < m_almInfoNum; ++almIdIdx) {
        if (m_almInfoArr[almIdIdx].almId == almId) {
            return almIdIdx;
        }
    }
    return almIdIdx;
}

VOS_BOOL EquipSigManager::IsCreated() const
{
    return m_isCreated;
}

VOS_BOOL EquipSigManager::IsRegReport() const
{
    return m_isRegRport;
}
