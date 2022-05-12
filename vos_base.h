#ifndef VOS_BASE_H
#define VOS_BASE_H
#include <iostream>
using namespace std;

#define VOS_UINT32  unsigned int
#define VOS_VOID    void
#define VOS_HANDEL_T unsigned int

#define VOS_OK 0
#define VOS_ERR 1

class RunLightCtrlCompTimer {
public:
    RunLightCtrlCompTimer() {};
    ~RunLightCtrlCompTimer() {};
    VOS_VOID Init(VOS_UINT32 timerName) {
        name = timerName;
    };
    VOS_VOID StartTimer(VOS_UINT32 delayTimeMs)
    {
        StopTimer();
        cout << "name = " << name;
        cout << "; delayTimeMs = " << delayTimeMs << endl;
    };
    VOS_VOID StopTimer() {
        cout << "stop" << endl;
    };
private:
    VOS_UINT32 name;
};


#endif // VOS_BASE_H