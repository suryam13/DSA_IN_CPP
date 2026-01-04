#include<bits/stdc++.h>
using namespace std;


/*
how -ve numbers are stored?
firstly 2's complement is used for having the digit in the compiler
then for the sign original MSB is considered.

for eg-  ~1

~1=111.....0(MSB -ve sign from here)
take 2's complement=1's complement + 1
=000...10=2(digit from here)

then the original output would be displayed as -2



to convert a negative decimal into bin take 2's complement of that decimal with positive integer
*/

 int main()
{
    int num=1;
    cout<<~num<<endl;
    
    //this would not give zero,because the operations operate on bit level,same behaviour is expected with bool data type too,since it's a bitwise operator


    //left shift operator 
    int a=15;
    cout<<(a<<2)<<endl; //a*(2^n)=60

    int b=10;
    cout<<(++b)*(b++)<<endl;
    

    return 0;
}