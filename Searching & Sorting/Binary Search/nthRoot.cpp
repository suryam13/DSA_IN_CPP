#include <bits/stdc++.h>
using namespace std;

/*
naive approach-linear search checking each number power,here T.C. would be O(m x log2n) logbase2n because pow function is used.

n=3 m=8  2^3==8 hence 2 is the answer
*/
int NthRoot(int n, int m)
{
    int start = 0;
    int end = m;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (pow(mid, n) == m)
            return mid;

        else if (pow(mid, n) < m)
            start = mid + 1;

        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return -1;

    //T.C : O(logbase2m +logbase2n)
}

int main()
{

    return 0;
}