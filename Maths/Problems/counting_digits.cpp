#include <bits/stdc++.h>
using namespace std;

int count(int n)
{   
    // int ct=(int)log10(n)+1; //alterate method
    int ct = 0;

    while (n != 0)
    {
        n = n / 10;
        ct++;
    }

    return ct;
}

int main()
{

    return 0;
}