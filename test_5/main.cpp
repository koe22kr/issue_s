#include "tester.h"



int main()
{
   // tester ta, tb;
   // mytester ma, mb;
   //
   // tester tempta = ta;
   // mytester tempma = ma;

    mymytester mmt;
    mymytester mmt2 = mmt;
   
    mytester* pmt = dynamic_cast<mytester*>(&mmt);
    sub* psub = dynamic_cast <sub*>(&mmt);
    pmt = &mmt;
    psub = &mmt;

    char* str = new char[100];
    delete[] str;
    long long bbb = 9223372036854775807;
    sizeof(bbb);
    return 0;
}