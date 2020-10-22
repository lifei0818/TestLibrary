#ifndef TESTMAIN_H
#define TESTMAIN_H

#include <iostream>
using namespace  std;
typedef int (WINAPI*QueryFromUpper)(DWORD,LPCSTR,LPCSTR*);
typedef int (WINAPI*LpFree)(LPCSTR &);
typedef int (WINAPI* LpTest)();
typedef void (WINAPI* SetServoState)(int state);
typedef void (WINAPI* JointJOG)(int jointIndex, int moveDirection, double speed);
typedef void (WINAPI* StopJOG)();			//停止点动
typedef bool (WINAPI* ProgramVelocity)(double vel);		//设置运行速度
typedef string (WINAPI* GetErrString)(int level);	///< 获取错误信息

///< RobotClient
class CTestRobotClient{
public:
    CTestRobotClient();
    ~CTestRobotClient();


    void testAPI();

private:
    bool LoadLibrary();
    LpTest m_LpTest;
    QueryFromUpper m_QueryFromUpper;
    LpFree m_LpFree;
    SetServoState m_SetServoState;
    JointJOG m_JointJOG;
    StopJOG m_StopJOG;
    ProgramVelocity m_ProgramVelocity;
    GetErrString m_GetErrString;

    LpTest m_waitCMDFinishFlag;

    HMODULE m_handle;
};

#endif
