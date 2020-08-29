#include <iostream>

class Empty
{

public:
    virtual void privatefunc() { std::cout << "It`s privatefunc" << std::endl; };

    static size_t g_int;
    enum EEmpty
    {
        a,b,c
    };
    typedef EEmpty Eempty;
    using eempty = EEmpty;
    void func()
    {
        std::cout << "It`s Empty" << std::endl; 
    }
};

class PrivateEmpty :private Empty
{
    void func1()
    {
        privatefunc();
    }
    int i = 0;
    
};

class PublicEmpty : public Empty
{
    void func2()
    {
        
    };
    int i = 0;

};
class HaveEmpty
{
    int i = 0;
    Empty m_Empty;

};

class MoreEmpty :public Empty
{
    

};

int main()
{
    sizeof(Empty);//1
    sizeof(PrivateEmpty);//4
    sizeof(PublicEmpty);//4
    sizeof(HaveEmpty);//8
    sizeof(MoreEmpty);//1

    


    return 0;
}