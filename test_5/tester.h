#pragma once
#include <iostream>

class sub
{
    int d = 9;
    virtual void func() {};
};
class tester
{public:
    int a = 1;
    tester(const tester& obj)=delete;
    tester() { vfunc(); };
    virtual void vfunc() { std::cout << "1" << std::endl; };
    ~tester()
    {
        vfunc();

    }
};

class mytester:public tester
{
public:
    int b = 2;
	mytester();
	~mytester();
   // mytester(const mytester& obj) {};
    virtual void vfunc() { std::cout << "2" << std::endl; };
    mytester(const mytester& obj) { std::cout << "copy2" << std::endl; };

    
private:

};


class mymytester :public mytester, public sub
{
public:
    int c = 3;
	mymytester();
	~mymytester();
    virtual void vfunc() { std::cout << "3" << std::endl; };
    mymytester(const mymytester& obj) { std::cout << "copy3" << std::endl; };
private:

};
