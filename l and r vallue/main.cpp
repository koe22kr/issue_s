#include <string>
#include <iostream>


const char* func1()
{
    return "asd";
}

std::string func2()
{
    return "asdf";
}

namespace detail {
    template <class T> struct value_category { static constexpr char const* value = "prvalue"; };
    template <class T> struct value_category<T&> { static constexpr char const* value = "lvalue"; };
    template <class T> struct value_category<T&&> { static constexpr char const* value = "xvalue"; };
}
#define PRINT_VALUE_CAT(expr) std::cout << #expr << " is a " << ::detail::value_category<decltype((expr))>::value << '\n'

struct S { int i; };

int main()
{
    
    
    
    const std::string& str1 = func1();
    std::string&& str3 = func2();
    //const std::string& str2 = func2();






    int r = 42;
    PRINT_VALUE_CAT(4); // prvalue
    PRINT_VALUE_CAT(r); // lvalue
    PRINT_VALUE_CAT(std::move(r)); // xvalue
    PRINT_VALUE_CAT(std::forward<int>(r));  // xvalue

    PRINT_VALUE_CAT(S{ 0 }); // prvalue
    PRINT_VALUE_CAT(S{ 0 }.i); // xvalue (gcc erroneously calls this a prvalue)



    //decltype(r) a;  //int
    //decltype((r)) a; //int&



    return 0;
}





