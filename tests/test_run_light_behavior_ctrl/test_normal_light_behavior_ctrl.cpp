#include "test_normal_light_behavior_ctrl.h"
#include "LedDriver.h"
#include "test_light_status_manager.h"
#include "run_light_ctrl_comp_log.h"

struct TestLightStatus {
    LightColor lightColor;
    VOS_UINT32 redStatus;
    VOS_UINT32 greenStatus;
    VOS_UINT32 blueStatus;
};

namespace {
    const TestLightStatus TEST_LIGHT_STATUS_LIST[] = {
        {LightColor::RED,    LED_ON,  LED_OFF, LED_OFF},
        {LightColor::GREEN,  LED_OFF, LED_ON,  LED_OFF},
        {LightColor::BLUE,   LED_OFF, LED_OFF, LED_ON},
        {LightColor::YELLOW, LED_ON,  LED_ON,  LED_OFF},
        {LightColor::PURPLE, LED_ON,  LED_OFF, LED_ON},
        {LightColor::CYAN,   LED_OFF, LED_ON,  LED_ON},
        {LightColor::WHITE,  LED_ON,  LED_ON,  LED_ON},
        {LightColor::BLACK,  LED_OFF, LED_OFF, LED_OFF},
    };

    const VOS_UINT32 TEST_LIGHT_STATUS_LIST_LEN = U16_ITEM_OF(TEST_LIGHT_STATUS_LIST);

    LightAction NORMAL_RED = {
        .actionType = ActionType::CONST,
        .lightColor = LightColor::RED,
        .luminace = MAX_LUMINANCE,
        .delayTime = 100,
        .para1 = 0,
        .para2 = 0
    };

    LightAction NORMAL_GREEN = {
        .actionType = ActionType::CONST,
        .lightColor = LightColor::GREEN,
        .luminace = MAX_LUMINANCE,
        .delayTime = 200,
        .para1 = 0,
        .para2 = 0
    };

    LightAction NORMAL_BLUE = {
        .actionType = ActionType::CONST,
        .lightColor = LightColor::BLUE,
        .luminace = MAX_LUMINANCE,
        .delayTime = 300,
        .para1 = 0,
        .para2 = 0
    };

    LightAction FLASH_YELLOW = {
        .actionType = ActionType::FLASH,
        .lightColor = LightColor::YELLOW,
        .luminace = MAX_LUMINANCE,
        .delayTime = 300,
        .para1 = 10,
        .para2 = 5
    };

    LightAction FLASH_PURPLE = {
        .actionType = ActionType::FLASH,
        .lightColor = LightColor::PURPLE,
        .luminace = MAX_LUMINANCE,
        .delayTime = 400,
        .para1 = 1,
        .para2 = 1
    };
}

TestNormalLightBehaviorCtrl::TestNormalLightBehaviorCtrl()
{
    m_testInst = RunLightBehaviorCtrl(m_normalLightCfg);
    m_testInst.Init(m_handle, m_lightIndex);
}

VOS_VOID TestNormalLightBehaviorCtrl::SetUpTestCase() {}
VOS_VOID TestNormalLightBehaviorCtrl::TearDownTestCase() {}

VOS_VOID TestNormalLightBehaviorCtrl::SetUp() {}

VOS_VOID TestNormalLightBehaviorCtrl::TearDown() {}

VOS_VOID TestNormalLightBehaviorCtrl::TestNormalLightBehavior(LightBehavior testBehavior)
{
    m_testInst.SetBehavior(testBehavior);
    for (VOS_UINT32 stage = 0; stage < testBehavior.componentNum; stage++) {
        LightBehaviorComp testComp = testBehavior.componentArr[stage];
        for (VOS_UINT32 loop = 0; loop < testComp.loopNum; loop++) {
            TestNormalLightAction(testComp.lightAction);
        }
    }
}

VOS_VOID TestNormalLightBehaviorCtrl::TestNormalLightAction(LightAction testAction)
{
    switch (testAction.actionType) {
        case ActionType::CONST: {
            TestNormalLightColor(testAction.lightColor);
            m_testInst.Run(m_lightIndex);
            break;
        }
        case ActionType::FLASH: {
            TestNormalLightFlashAction(testAction);
            break;
        }
        default: {
            break;
        }
    }
}

VOS_VOID TestNormalLightBehaviorCtrl::TestNormalLightFlashAction(LightAction testAction)
{
    for (VOS_UINT32 step = 0; step <= testAction.para1 + testAction.para2; step++) {
        if (step <= testAction.para1) {
            TestNormalLightColor(testAction.lightColor);
        } else {
            TestNormalLightColor(LightColor::BLACK);
        }
        if (step != 0) {
            m_testInst.Run(m_lightIndex);
        }
    }
}

VOS_VOID TestNormalLightBehaviorCtrl::TestNormalLightColor(LightColor expectColor)
{
    for (VOS_UINT32 i = 0; i < TEST_LIGHT_STATUS_LIST_LEN; i++) {
        if (TEST_LIGHT_STATUS_LIST[i].lightColor != expectColor) {
            continue;
        }
        TEST_LIGHT_STATUS(m_normalLightCfg.redId,   TEST_LIGHT_STATUS_LIST[i].redStatus);
        TEST_LIGHT_STATUS(m_normalLightCfg.greenId, TEST_LIGHT_STATUS_LIST[i].greenStatus);
        TEST_LIGHT_STATUS(m_normalLightCfg.blueId,  TEST_LIGHT_STATUS_LIST[i].blueStatus);
        break;
    }
}

TEST_F(TestNormalLightBehaviorCtrl, NORMAL)
{
    LightBehaviorComp testComp[] = {{NORMAL_RED, 5}};
    LightBehavior testBehavior = {
        .componentArr = testComp,
        .componentNum = U16_ITEM_OF(testComp)
    };
    TestNormalLightBehavior(testBehavior);
}

TEST_F(TestNormalLightBehaviorCtrl, FLASH)
{
    LightBehaviorComp testComp[] = {{FLASH_YELLOW, 1}};
    LightBehavior testBehavior = {
        .componentArr = testComp,
        .componentNum = U16_ITEM_OF(testComp)
    };
    TestNormalLightBehavior(testBehavior);
}

TEST_F(TestNormalLightBehaviorCtrl, MIX)
{
    static LightBehaviorComp testComp[] = {
        {NORMAL_RED,   1},
        {FLASH_YELLOW, 1},
        {NORMAL_GREEN, 2},
        {FLASH_PURPLE, 1},
        {NORMAL_BLUE,  3}, 
    };
    static LightBehavior testBehavior = {
        .componentArr = testComp,
        .componentNum = U16_ITEM_OF(testComp)
    };
    for (VOS_UINT32 i = 0; i < 5; i++) {
        TestNormalLightBehavior(testBehavior);
    }
    
}
