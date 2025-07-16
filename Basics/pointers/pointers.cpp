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