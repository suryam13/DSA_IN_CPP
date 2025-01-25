#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    // alternate method
    //  for(int i=0;i<=30;i++)
    //  {
    //      int ans=pow(2,i);

    //     if(ans==n)
    //     return true;
    // }

    if (n < 0)
        return false;

    int count = 0;
    while (n != 0)
    {
        if (n & 1)
            count++;

        n = n >> 1;
    }

    if (count == 1)
        return true;

    else
        return false;
}
int main()
{

    return 0;
}