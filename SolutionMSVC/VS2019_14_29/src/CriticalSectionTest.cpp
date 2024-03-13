// ÁÙ½çÇø
#include <iostream>
#include <windows.h>
#include <thread>
using namespace std;
CRITICAL_SECTION g_cs;

int g_Count = 0;
void func1()
{
	while (1)
	{
		cout << ">>>>> t1 g_Count = " << g_Count << endl;
		EnterCriticalSection(&g_cs);
		g_Count = g_Count + 1000;
		cout << "t1 g_Count = " << g_Count << endl;
		Sleep(3000);
		LeaveCriticalSection(&g_cs);
	}
}

void func2()
{
	while (1)
	{
		cout << ">>>>>>> t2 g_Count = " << g_Count << endl;
		EnterCriticalSection(&g_cs);
		g_Count++;
		cout << "t2 g_Count = " << g_Count << endl;
		Sleep(2000);
		LeaveCriticalSection(&g_cs);
	}
}
int CriticalSectioTest()
{
	InitializeCriticalSection(&g_cs);
	std::thread t1(func1); // t1 is not a thread
	std::thread t2(func2); // t1 is not a thread
	t1.join();
	t2.join();

	cin.get();
	DeleteCriticalSection(&g_cs);
	return 0;
}