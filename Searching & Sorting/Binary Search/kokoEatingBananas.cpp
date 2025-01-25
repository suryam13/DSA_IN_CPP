#include <bits/stdc++.h>
using namespace std;

/*
L.C-875

In binary search always remember if earlier start was not possible as answer,then it would point to the possible at the end of the loop and vice-verca,same goes with the end

for eg here the piles were  3 6 7 11 and the target was 8 hrs so here the range would be from 1 to max(piles),initially considering 1 it would take total of 27 hrs ending up eating all the bananas so it was not possible but on the opposite side 11 was possible as it would take total 4 hrs,hence it was possible but we have to find minimum k value such that it satisfies the condition.
henceforth here start would be returned if ans varaible is to be avoided.

k means tha amount of bananas koko will eat per hr,on dividing which will be a ceil value,keep on adding the hrs till the end of the piles.
for eg for k=2  2+3+4+6=15hrs

*/

long long totalHours(vector<int> &piles, int mid, int h)
{
    long long sum = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        int store = ceil((double)piles[i] / (double)mid);
        sum = sum + store;

        if (sum > h)
            break;  //to avoid the overflow 
    }
    return sum;
}

int minEatingSpeed(vector<int> &piles, int h)
{

    int start = 1;
    int end = *max_element(piles.begin(), piles.end());
    int mid = start + (end - start) / 2;
    int ans = end;

    while (start <= end)
    {
        int total = totalHours(piles, mid, h);
        cout << total;

        if (total <= h)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;

        mid = start + (end - start) / 2;
    }
    return ans;

    //T.C. O(n+log(max_element))
}

int main()
{

    return 0;
}