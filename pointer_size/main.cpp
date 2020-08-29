#include <iostream>
#include <functional>
class base1
{
public:
    void basefunc1() {};
    void base() 
    {
        std::cout << sizeof(this) << std::endl;
    };
};
class base2
{
public:
    void basefunc2() {};
    void base1() {
        std::cout << sizeof(this) << std::endl;
    };
};
class Vbase1
{
public:
    virtual  void basefunc3() {};
    virtual void base() 
    {
        std::cout << sizeof(this) << std::endl;
    };
};
class Vbase2
{
public:
    virtual  void basefunc4() {};
    virtual void base1()
    {
        std::cout << sizeof(this) << std::endl;
    };


};
class Vbase3
{
public:
    virtual void virtualfunc() {};
};
class Vbase4
{
public:
    virtual void virtualfunc2() {};
};
class empty
{
public:
    void emptyfunc() {};
private:

};
class empty2
{
public:
    void emptyfunc2() {};
private:

};
class empty3
{
public:
    void emptyfunc3() {};
private:

};
class derived1 : public base1
{
};
class derived2 : public base1 , public base2
{
};
class derived3 : public Vbase1,public base2
{
};
class derived4 :  public Vbase1, public Vbase2
{
};
class virtualsizer :virtual public Vbase1,virtual public Vbase2
{
};


int main()
{
    base1 b1;
    base2 b2;
    Vbase1 b3;
    Vbase2 b4;
    derived1 d1;
    derived2 d2;
    derived3 d3;
    derived4 d4;
    auto msize1 = sizeof(d1);//1
    auto msize2 = sizeof(d2);//1   //하지만 인터페이스 3개 상속받으면 size = 2. 그후로 하나 받을때 마다 1씩 추가.
    auto msize3 = sizeof(d3);//8   vt ptr이 가상 상속 하나당 추가.(+8바이트)
    auto msize4 = sizeof(d4);//16
    auto msize5 = sizeof(virtualsizer);

    auto size1 = sizeof(&b1);
    auto size2 = sizeof(&b2);
    auto size3 = sizeof(&b3);
    auto size4 = sizeof(&b4);

    auto size5 = sizeof(&d1);
    auto size6 = sizeof(&d2);
    auto size7 = sizeof(&d3);
    auto size8 = sizeof(&d4);
  
    //일단은 base, 
    typedef void (derived1::*fp1)(void);
    fp1 v1 = &derived1::base;
    (d1.*v1)();
    std::cout << "d1 : " << sizeof(v1) << std::endl;//8

    typedef void (derived2::*fp2)(void);
    fp2 v2 = &derived2::base;
    (d2.*v2)();
    std::cout << "d2 : " << sizeof(v2) << std::endl;//16

    typedef void (derived3::*fp3)(void);
    fp3 v3 = &derived3::base;
    (d3.*v3)();
    std::cout << "d3 : " << sizeof(v3) << std::endl;//8

    typedef void (derived4::*fp4)(void);
    fp4 v4 = &derived4::base;
    (d4.*v4)();
    std::cout << "d4 : " << sizeof(v4) << std::endl;//16

    class No;
    typedef void (No::*fp5)(void);
   
    std::cout << "d5 : " << sizeof(fp5) << std::endl;//24
    std::function<void(base1&)> ttt = &base1::base;
    
    
    int end = 999;
    return 0;
}