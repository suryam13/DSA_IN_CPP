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

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 10;
    int *b = &a;
    int **ptr = &b; //pointer ka pointer toh **
    cout<<"address of a : " << b<<endl; // b stores address of a 
    cout<<"address of a : " << &a<<endl;
    cout<<ptr<<endl; //address of b 
    cout<<&b<<endl; //address of b 
    cout<<*ptr<<endl; //when u do 1 time * it means dereference b matlab b ke jagah p//kya hai =>  a ka address
    cout<<**ptr;//means ptr ko 2 baar dereference karo ek baar ke b upar jo 
    //a ka address hai wo aayega usko kiya to jo a ka address hai uspe kya hai 
    //=>10
    return 0;
}