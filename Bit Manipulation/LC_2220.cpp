#include <bits/stdc++.h>
using namespace std;
int minBitFlips(int start, int goal)
{

    // bitwise & approach
    //  int count0 = 0;
    //  int count1 = 0;
    //  int ans = 0;

    // int goal0 = goal;
    // int start0 = start;

    // while (goal0 != 0) {
    //     goal0 = goal0 >> 1;
    //     count0++;
    // }

    // while (start0 != 0) {
    //     start0 = start0 >> 1;
    //     count1++;
    // }

    // int maxi = max(count0, count1);

    int ans = 0;

    while (start != 0 || goal != 0)
    {
        bool comp1 = (start & 1);
        bool comp2 = (goal & 1);

        if (comp1 != comp2)
        {
            ans++;
        }

        goal = goal >> 1;
        start = start >> 1;

        // maxi--;
    }

    return ans;

    // bitwise xor approach
    //  int cont=goal^start;
    //  int ans=0;

    // while(cont!=0)
    // {
    //     if(cont&1)
    //     ans++;

    //     cont=cont>>1;
    // }

    // return ans;
}

int main()
{

    return 0;
}