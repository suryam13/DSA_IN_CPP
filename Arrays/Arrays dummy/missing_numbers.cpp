#include <bits/stdc++.h>
using namespace std;

/*

values are in the range 0 to N
eg : 0 1 2 (3 is missing)

another method:sum approach,sort and compare index approach

*/
int missing(int arr[], int n)
{
    // x-oring array elments till end
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    // x-oring from 0 to n
    for (int i = 0; i <= n; i++)
    {
        ans = ans ^ i;
    }

    return ans;
}

int main()
{

    return 0;
}