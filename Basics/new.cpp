#include<bits/stdc++.h>
using namespace std;

 int main()
{   

    string bin;

    int num=10;

    bin=bitset<8>(num).to_string();

    cout<<bin;
    
    return 0;
}