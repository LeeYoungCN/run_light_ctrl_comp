#ifndef EQUIP_SIG_MANAGER_H
#define EQUIP_SIG_MANAGER_H
#include "system_status_manager_def.h"

class EquipSigManager {
public:
    EquipSigManager() = default;
    EquipSigManager(VOS_UINT32 equipId, EquipSigCfg equipSigCfg);

    // 设备增删
    VOS_VOID AddEquip();
    VOS_VOID DelEquip();
    // 获取属性
    VOS_UINT16 GetTypeId() const;
    VOS_UINT16 GetEquipId() const;
    VOS_BOOL   IsNeedRegAlmReport() const;
    // 获取信号值
    VOS_UINT16 GetSignalValue(VOS_UINT16 sigId, VOS_UINT32 &sigVal) const;
    VOS_UINT16 GetSignalValue(VOS_UINT16 sigId, VOS_INT32  &sigVal) const;
    VOS_UINT16 GetSignalValue(VOS_UINT16 sigId, VOS_FLOAT  &sigVal) const;
    VOS_UINT16 GetAlarmStatusl(VOS_UINT16 almId, VOS_UINT32 &status) const;
    // 信号值刷新
    VOS_UINT16 RefreshSignalValue(VOS_UINT16 sigId, VOS_UINT32 sigVal);
    VOS_UINT16 RefreshAlarmStatus(VOS_UINT16 almId, VOS_UINT32 status);

    VOS_BOOL IsMyEqupId(VOS_UINT16 equipId) const;

private:
    VOS_BOOL   IsCreated() const;
    VOS_BOOL   IsRegReport() const;
    VOS_UINT32 FindSigIdIndex(VOS_UINT16 sigId) const;
    VOS_UINT32 FindAlmIdIndex(VOS_UINT16 almId) const;

    VOS_UINT16 m_equipId = 0;
    VOS_UINT16 m_typeId  = 0;

    RlcCompSigInfo *m_sigInfoArr = VOS_NULL_PTR;
    VOS_UINT32      m_sigInfoNum = 0;
    RlcComAlmInfo  *m_almInfoArr = VOS_NULL_PTR;
    VOS_UINT32      m_almInfoNum = 0;

    VOS_BOOL   m_isRegRport = VOS_FALSE;
    VOS_BOOL   m_isCreated  = VOS_FALSE;

};

#endif // EQUIP_SIG_MANAGER_H