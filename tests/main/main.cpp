#include <iostream>
#include "gtest/gtest.h"
#include "emap_so_log.h"

int main(int argc, char *argv[])
{
    InitLogPrint(LogSwitch::ON, EMAP_PRINT_LEVEL_ERROR);

    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
