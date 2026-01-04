#include <bits/stdc++.h>
using namespace std;
// L.C.322
//not understood through recursion
/*Incorect Solution-*/
//as it is asked to give the minimum number of coins but i am using greedy approach which would not be correct all the times
//suppose target is 6 and i have the coin 1 3 4 according to my i will use 1 4 coin and 2 coin but optimal is usingf 2 3 coins
int coinChange(vector<int> &coins, int amount)
{

    sort(coins.begin(), coins.end());

    int temp = coins.size() - 1;
    int count = 0;
    int dummy = 0;

    while (amount != 0 && temp >= 0)
    {
        if ((amount / coins[temp]) != 0)
        {
            dummy = amount / coins[temp];
            count = count + dummy;

            amount = amount - (coins[temp] * dummy);
        }

        temp--;
    }

    if (amount == 0)
        return count;

    return -1;
}
int main()
{

    return 0;
}