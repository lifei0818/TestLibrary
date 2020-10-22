#include "baselib.h"
#include "TestMain.h"


CTestRobotClient::CTestRobotClient()
    :m_handle(NULL)
{
    this->LoadLibrary();
}

CTestRobotClient::~CTestRobotClient(){
    FreeLibrary(m_handle);
}

bool CTestRobotClient::LoadLibrary()
{
    m_handle = ::LoadLibrary(_T("H:\\workspace\\CMake\\robotServer\\lib\\Debug\\RobotClient.dll"));
    if (m_handle == NULL)
    {
        printf("err=%s\r\n");
        return false;
    }

    m_LpTest = (LpTest)GetProcAddress(m_handle, "LpTest");
    m_QueryFromUpper = (QueryFromUpper)GetProcAddress(m_handle, "QueryFromUpper");
    m_LpFree = (LpFree)GetProcAddress(m_handle, "LpFree");
	///<设置伺服状态
    m_SetServoState = (SetServoState)GetProcAddress(m_handle, "SetServoState");
    m_JointJOG = (JointJOG)GetProcAddress(m_handle, "JointJOG");
    m_StopJOG = (StopJOG)GetProcAddress(m_handle, "StopJOG");
    m_ProgramVelocity = (ProgramVelocity)GetProcAddress(m_handle, "ProgramVelocity");
    m_GetErrString = (GetErrString)GetProcAddress(m_handle, "GetErrString");

    m_waitCMDFinishFlag=(LpTest)GetProcAddress(m_handle, "WaitCMDFinishFlag");

    if(m_QueryFromUpper&&m_LpTest&&m_LpFree
            &&m_SetServoState&&m_JointJOG&&m_StopJOG
            &&m_ProgramVelocity&&m_GetErrString)
    {
        return true;
    }else{
        cout<< "load API false"<<endl;
        return false;
    }
}
void CTestRobotClient::testAPI(){
    cout<< "*****************************RobotClient.dll*********************************"<<endl;
    
    LPCSTR lpStr;
    m_QueryFromUpper(3,"I am in Test!",&lpStr);
    string strTest(lpStr);
    cout << lpStr << endl;
    m_LpFree(lpStr);
#if 1
    string strJs("{\"robotname\":\"Robot\",\
                    \"ip\":\"192.168.2.10\",\
                    \"port\":1234}");
    string strName("Robot");
    m_QueryFromUpper(0,strName.c_str(),&lpStr);
    m_QueryFromUpper(0x11,strJs.c_str(),&lpStr);
    cout <<"伺服打开"<<endl;
    m_SetServoState(1);
    m_waitCMDFinishFlag();
    m_QueryFromUpper(0x14,strJs.c_str(),&lpStr);
    cout << "RobotMotion:" << lpStr << endl;
    int i=-100;
    while (i++) {
        m_JointJOG(0,0,0.2);
        Sleep(1000);
        m_StopJOG();
        m_waitCMDFinishFlag();
        m_JointJOG(0,1,0.2);
        Sleep(1000);
        m_StopJOG();
        m_waitCMDFinishFlag();
    }
#endif

}
