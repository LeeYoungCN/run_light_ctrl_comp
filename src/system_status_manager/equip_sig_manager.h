#ifndef EQUIP_SIG_MANAGER_H
#define EQUIP_SIG_MANAGER_H
#include "system_status_manager_def.h"

class EquipSigManager {
public:
    EquipSigManager() = default;
    EquipSigManager(VOS_UINT32 equipId, EquipSigCfg equipSigCfg);
    // 设备增删
    VOS_VOID AddEquip(VOS_UINT16 typeId, VOS_UINT16 equipId, VOS_UINT16 phySlot);
    VOS_VOID DelEquip(VOS_UINT16 typeId, VOS_UINT16 equipId);
    // 获取属性
    VOS_UINT16 GetTypeId() const;
    VOS_UINT16 GetEquipId() const;
    VOS_BOOL   IsNeedRegAlmReport() const;
    // 获取信号值
    VOS_UINT16 GetSetSigVal(VOS_UINT16 setSigId, VOS_UINT32 &sigVal) const;
    VOS_UINT16 GetSetSigVal(VOS_UINT16 setSigId, VOS_INT32  &sigVal) const;
    VOS_UINT16 GetSetSigVal(VOS_UINT16 setSigId, VOS_FLOAT  &sigVal) const;
    VOS_UINT16 GetAlmSigVal(VOS_UINT16 almSigId, VOS_UINT32 &sigVal) const;
    // 信号值刷新
    VOS_UINT16 RefreshSetSigVal(VOS_UINT16 setSigId, VOS_UINT8 *sigVal, VOS_UINT32 sigSize);
    VOS_UINT16 RefreshAlmSigVal(VOS_UINT16 almSigId, VOS_UINT32 sigVal);

    VOS_UINT16 IsMySigId(VOS_UINT16 typeId, VOS_UINT16 equipId, VOS_UINT16 sigId);

private:
    VOS_BOOL   IsCreated() const;
    VOS_BOOL   IsRegReport() const;
    VOS_UINT32 GetSigIdIndex(VOS_UINT16 sigId, SigInfo *sigInfo, VOS_UINT32 sigNum) const;

    VOS_UINT16 m_equipId = 0;
    VOS_UINT16 m_typeId  = 0;
    VOS_UINT16 m_phySlot = 0;

    SigInfo   *m_setSigInfo = VOS_NULL_PTR;
    VOS_UINT32 m_setSigNum  = 0;
    SigInfo   *m_almSigInfo = VOS_NULL_PTR;
    VOS_UINT32 m_almSigNum  = 0;

    VOS_BOOL   m_isRegRport = VOS_FALSE;
    VOS_BOOL   m_isCreated  = VOS_FALSE;

};

#endif // EQUIP_SIG_MANAGER_H