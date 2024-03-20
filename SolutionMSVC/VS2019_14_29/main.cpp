#include <Windows.h>
#include <cstdio>
#include <iostream>
#include "src/testList.h"

using namespace std;

int main(){
    //SetConsoleOutputCP(CP_UTF8);
    SetConsoleOutputCP(936);

    //test01string();
    test02vector();
    //test04ptr();
    return 0;
}

/*
xmemory 1040 _Alloc_proxy 函数 注释了一行 看看有啥后果

*/

/*
xmemory 
不能 #include <iostream>











*/