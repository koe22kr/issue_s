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
    

    ::InitializeCriticalSection(&CS); //���� ������ ���� ����.... �׷� ��????,....��������
                                      //�޾� �������� ���갡 �ȵǴ� ��찡 �־��µ� ���� �����ϱ�..��������;
    std::thread t1(func);
    std::thread t2(func);
    std::thread t3(func);




    t1.join();
    t2.join();
    t3.join();

    

    DeleteCriticalSection(&CS);




    return 0;
}