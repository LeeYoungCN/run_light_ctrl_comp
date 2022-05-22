#include "emap_so_log.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctime>
#include <iostream>

const VOS_CHAR* GetFileName(const VOS_CHAR* filePath);
std::string GetTime();

VOS_VOID EMAP_LogPrint(VOS_UINT16 u16ModId, VOS_UINT8 u8Level, const VOS_CHAR *fileName, VOS_UINT32 u32Line, const VOS_CHAR *fmt, ...)
{
    printf("%s %s[%u] ", GetTime().c_str(), GetFileName(fileName), u32Line);

    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);

    printf("\n");
}

const VOS_CHAR* GetFileName(const VOS_CHAR* filePath)
{
    VOS_UINT32 len = strlen(filePath);
    VOS_UINT32 startPos = 0;
    for (VOS_UINT32 i = 0; i < len; i++) {
        if(filePath[i] == '\\' || filePath[i] == '/') {
            startPos = i;
        }
    }

    return (startPos > 0 ? filePath + startPos + 1 : filePath);
}

std::string GetTime()
{
    std::string timeStr;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    auto toStr = [](int time_data, string symbol) -> std::string {
        std::string ret;
        if (time_data < 10) {
            ret += "0";
        }
        ret += to_string(time_data) + symbol;
        return ret;
    };
    timeStr += toStr(1900 + ltm->tm_year, "-");
    timeStr += toStr(ltm->tm_mon + 1,  "-");
    timeStr += toStr(ltm->tm_mday, " ");
    timeStr += toStr(ltm->tm_hour, ":");
    timeStr += toStr(ltm->tm_min,  ":");
    timeStr += toStr(ltm->tm_sec,  "");
    return timeStr;
}
