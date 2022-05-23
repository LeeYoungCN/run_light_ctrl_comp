#ifndef TEST_RUN_LIGHT_BEHAVIOR_CTRL_H
#define TEST_RUN_LIGHT_BEHAVIOR_CTRL_H
#include "gtest/gtest.h"
#include "vos_base.h"
#include "vos_handle.h"
#include "DevId.h"
#include "run_light_behavior_ctrl.h"

class TestNormalLightBehaviorCtrl : public testing::Test {
public:
    TestNormalLightBehaviorCtrl();
    ~TestNormalLightBehaviorCtrl() = default;
protected:
    static VOS_VOID SetUpTestCase();
    static VOS_VOID TearDownTestCase();

    VOS_VOID SetUp();
    VOS_VOID TearDown();
    VOS_VOID TestNormalLightBehavior(LightBehavior testBehaviot);
    VOS_VOID TestNormalLightAction(LightAction testAction);
    VOS_VOID TestNormalLightFlashAction(LightAction testAction);
    VOS_VOID TestNormalLightColor(LightColor expectColor);

    NormalLightGroupPara m_normalLightCfg = {LED0_ID, LED1_ID, LED2_ID};
    RunLightBehaviorCtrl m_testInst;
    VOS_HANDLE_T m_handle = 1;
    VOS_UINT32   m_lightIndex = 1;
};


#endif // TEST_RUN_LIGHT_BEHAVIOR_CTRL_H
