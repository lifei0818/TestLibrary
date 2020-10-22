#include "baselib.h"
#include "TestMain.h"
#include <string>
#include <iostream>
using namespace  std;
int main()
{
    CTestRobotClient testRob;
    testRob.testAPI();
    cout << "hello world!"<<endl;
}
