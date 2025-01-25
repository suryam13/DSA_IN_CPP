#include <bits/stdc++.h>
using namespace std;
// LC-70
int climbStairs(int n)
{

    // logic is correct but needs to be optimized through DP
    
    if (n == 0) // means i am on the ground floor so 1 way(hypothetical i jump on the same ground floor and reach there)
    {
        return 1;
    }

    if (n == 1) // can come on first only from the ground floor
        return 1;

    return climbStairs(n - 1) + climbStairs(n - 2);
    // reason being is that if i am on the top floor then there are two ways to reach to top floor at current either i have to take 1 step or 2 step hence (n-1)+(n-2)
}

int main()
{

    cout<<climbStairs(3);
    return 0;
}