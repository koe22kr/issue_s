#include <thread>
#include <mutex>
#include <iostream>
#include <atomic>
#include <Windows.h>

std::atomic_int value = 0;
std::atomic_bool flag = true;
std::atomic_int64_t count1 = 0;
std::atomic_int64_t count2 = 0;

void func1023()
{
	while (flag)
	{
		value = 1023;
		Sleep(100);
		count1++;
	}
	return;
}
void func0()
{
	while (flag)
	{
		value = 0;
		Sleep(100);
		count2++;
	}
	return;
}

int main()
{
	std::thread t1(func1023);
	std::thread t2(func0);

	while (flag)
	{
		int temp = value;
		if (value != 1023 && value != 0)
		{
			flag = false;
			t1.join();
			t2.join();
			std::cout << "value is not 1023 or 0 = " << temp << std::endl;
		}
	}
	return 0;
}