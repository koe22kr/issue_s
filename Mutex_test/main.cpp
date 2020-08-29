#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <iostream>

static int value = 0;
static int value2 = 0;
std::atomic_int value3 = 0;


std::mutex mtx;

class MyGuard
{
	std::mutex* mtx;
public:
	MyGuard();
	~MyGuard();

private:

};

MyGuard::MyGuard()
{
	mtx->lock();
}

MyGuard::~MyGuard()
{
	mtx->unlock();
}



void func()
{
	for (size_t i = 0; i < 1'000'005; i++)
	{
		value++;
		//{
		//	mtx.lock();
		//	value2++;
		//	mtx.unlock();
		//
		//}
		//value3++;
	}
}
void func2()
{
	for (size_t i = 0; i < 1'000'000; i++)
	{
		value--;
		//{
		//	mtx.lock();
		//	value2--;
		//	mtx.unlock();
		//
		//}
		//value3--;
	}
}
void func3()
{
	for (size_t i = 0; i < 1'000'005; i++)
	{
		//value++;
		{
			mtx.lock();
			value2++;
			mtx.unlock();
		
		}
		//value3++;
	}
}
void func4()
{
	for (size_t i = 0; i < 1'000'000; i++)
	{
		//value--;
		{
			mtx.lock();
			value2--;
			mtx.unlock();
		
		}
		//value3--;
	}
}void func5()
{
	for (size_t i = 0; i < 1'000'005; i++)
	{
		//value++;
		//{
		//	mtx.lock();
		//	value2++;
		//	mtx.unlock();
		//
		//}
		value3++;
	}
}
void func6()
{
	for (size_t i = 0; i < 1'000'000; i++)
	{
		//value--;
		//{
		//	mtx.lock();
		//	value2--;
		//	mtx.unlock();
		//
		//}
		value3--;
	}
}


int main()
{
	auto start = std::chrono::steady_clock::now();

	std::thread t1(func);
	std::thread t2(func2);
	
		t1.join();
		t2.join();

		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		double temp = elapsed_seconds.count();

		//

		start = std::chrono::steady_clock::now();

		std::thread t3(func3);
		std::thread t4(func4);

		t3.join();
		t4.join();

		end = std::chrono::steady_clock::now();
		elapsed_seconds = end - start;
		double temp2 = elapsed_seconds.count();

		//

		start = std::chrono::steady_clock::now();

		std::thread t5(func5);
		std::thread t6(func6);

		t5.join();
		t6.join();

		end = std::chrono::steady_clock::now();
		elapsed_seconds = end - start;
		double temp3 = elapsed_seconds.count();












		//std::cout << "value = " << value << " || value2 = " << value2 << " || value3 = " << value3 << std::endl;
		return 0;
	}







