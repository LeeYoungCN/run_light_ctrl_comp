#ifndef SYSTEM_STATUS_SAMPLE_H
#define SYSTEM_STATUS_SAMPLE_H
#include "system_status_manager_def.h"

// 状态代号
const VOS_UINT32 SYSTEM_STATUS_UPGREADE   = 0x1001; // 升级
const VOS_UINT32 SYSTEM_STATUS_ALARM      = 0x1002; // 告警
const VOS_UINT32 SYSTEM_STATUS_COMM_FAULT = 0x1003; // 通讯失败

const VOS_UINT16 TPD_ALM_COMM_FAULT = 0x16;

enum class SigType {
    SET_SIG,
    ALM_SIG
};

struct SystemStatusCfg {
    VOS_UINT32 StatusId;
    VOS_UINT16 sigId;
    SigType sigType; // 设置信号/告警信号
};

SystemStatusCfg commFail = {
    SYSTEM_STATUS_COMM_FAULT,
    TPD_ALM_COMM_FAULT,
    SigType::ALM_SIG,
};

class SystemStatusSample {
public:
    SystemStatusSample();
    ~SystemStatusSample();

    VOS_VOID Init();
private:
    VOS_VOID ProcProdMsg();
    VOS_VOID ProcTimeMsg();

    // VOS_UINT32 m_almNum = 0; // 告警数量
    // VOS_UINT32 *m_statusList = VOS_NULL_PTR;

};
// 升级 > 待机 > 工作
#endif // SYSTEM_STATUS_SAMPLE_H

// 告警：存在告警, 则