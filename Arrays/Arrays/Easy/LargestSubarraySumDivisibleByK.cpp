#include <bits/stdc++.h>
using namespace std;
//gfg
int longSubarrWthSumDivByK(int arr[], int n, int k)
{
    map<long long, int> mapy;
    // key is the remainder whereas value is the index where it is present
    // if two remainders happens to be same then that can be considered as a subarray which is divisible by k

    int maxLen = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        int rem = sum % k;

        if (rem == 0)
        {
            maxLen = max(maxLen, i + 1);
        }

        if (rem < 0)
        { // if remainder turns out to be negative then make it positive
            rem = rem + k;
        }

        if (mapy.find(rem) != mapy.end())
        {
            // means the remainder is present
            int len = i - mapy[rem];
            maxLen = max(maxLen, len);
        }

        else
        {
            // means remainder is not present then make a entry of that
            mapy[rem] = i;
        }
    }
    return maxLen;
}

int main()
{

    return 0;
}