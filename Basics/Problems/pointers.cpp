#include<bits/stdc++.h>
using namespace std;

 int main()
{
    //there is a concept of double pointers as well in c++
    //double pointer is a pointer that points to another pointer and it is declared using two asterisks.

    int a=10;
    int *p=&a; //p is a pointer that points to the address of a.

    cout<<p<<endl; //address of a
    cout<<*p<<endl; //value of a
    cout<<&p<<endl; //address of p 
    //note that &p is the address of p, not the address of a.

    int **pp=&p; //pp is a double pointer that points to the address of p.
    //pp is a pointer to another pointer so it would eb double asterisk.

    cout<<pp<<endl; //address of p
    cout<<*pp<<endl; //it means dereference what is stored in pp that is address of a
    cout<<**pp<<endl; //douvle reference what
    return 0;
}