#include <thread>
#include <iostream>
#include <atomic>

int prev_value;
std::atomic_int error_count;
void func(int* in_value)
{
    //int ref_value = *in_value;

    for (size_t i = 0; i < 1000000; i++)
    {
        if (prev_value > *in_value)
        {
            error_count++;
        }

       ++(*in_value);
       prev_value = *in_value;
    }

}


int main()
{

    int value = 100;

    std::thread t1(func, &value);
    std::thread t2(func, &value);




    t1.join();
    t2.join();






    return 0;
}