#ifndef LIGHT_STATUS_MANAGER_H
#define LIGHT_STATUS_MANAGER_H
#include "vos_base.h"
#include <map>

#define INS(className) className::GetInstance()
#define TEST_LIGHT_STATUS(lightId, expectStatus) \
    EXPECT_EQ(INS(LightStatusManager).GetLightStatus(lightId), \
              static_cast<VOS_UINT32>(expectStatus))

class LightStatusManager {
public:
    static LightStatusManager &GetInstance();

public:
    VOS_VOID   SetLightStatus(VOS_UINT32 lightId, VOS_UINT32 status);
    VOS_UINT32 GetLightStatus(VOS_UINT32 lightId);

private:
    LightStatusManager();
    ~LightStatusManager() = default;

    std::map<VOS_UINT32, VOS_UINT32> m_statusMap;
};

#endif // LIGHT_STATUS_MANAGER_H
