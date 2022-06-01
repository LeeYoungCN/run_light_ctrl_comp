#include "system_status_manager.h"

SystemStatusSample::SystemStatusSample() {}

SystemStatusSample::~SystemStatusSample() {}

VOS_VOID SystemStatusSample::Init()
{
    // 所有告警主动上报
    // 设置信号主动上报
}

// 处理产品信息
VOS_VOID SystemStatusSample::ProcProdMsg()
{
    // 升级中
}

// 处理定时器消息
VOS_VOID SystemStatusSample::ProcTimeMsg()
{
    // 升级状态查询
}

// 两个灯，至少两组