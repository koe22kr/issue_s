#include <Windows.h>
#include <thread>


CRITICAL_SECTION CS;

size_t szt;

void func()
{
    for (size_t i = 0; i < 100; i++)
    {
        ::EnterCriticalSection(&CS);
        szt++;
        ::LeaveCriticalSection(&CS);
    }

  
}

int main()
{
    

    ::InitializeCriticalSection(&CS); //하지 않으면 예외 나옴.... 그럼 왜????,....ㅁㄴㅇㄹ
                                      //펄업 문제에서 리브가 안되는 경우가 있었는데 무슨 문제일까..ㅁㄴㅇㄹ;
    std::thread t1(func);
    std::thread t2(func);
    std::thread t3(func);




    t1.join();
    t2.join();
    t3.join();

    

    DeleteCriticalSection(&CS);




    return 0;
}