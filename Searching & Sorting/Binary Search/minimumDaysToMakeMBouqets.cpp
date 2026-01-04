#include <bits/stdc++.h>
using namespace std;

// LC-1482

/*
k=no.of adjacent flowers to make a single bouqet
m=total no.of bouqets required
to return miniumum number of days required to make the desired number of bouqets
consecutive bloomed flowers are required to make a single bouqet

*/

bool findans(vector<int> &bloomDay, int m, int k, int mid)
{
    int count = 0;
    int bouqets = 0;

    for (int i = 0; i < bloomDay.size(); i++)
    {
        int dummy = ceil((double)bloomDay[i] / (double)mid); // to round off to the higher int

        // either can use this also
        // if (bloomDay[i]<=mid) {
        //     count++;//it means that the flower has bloomed

        if (dummy <= 1) // it means that the flower has bloomed
        {
            count++;

            if (count == k) // it means that it is consecutive to make a bouqet
            {
                bouqets++;
                count = 0; // to reset the consecutiveness to zero if bouqet is formed
            }
        }
        else
            count = 0;
    }

    if (bouqets >= m) // required bouqets
        return true;

    return false; // not enough bouqets
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    // the range of days would be between 1 to max number of days in the array that is required to bloom
    int start = *min_element(bloomDay.begin(), bloomDay.end());
    int end = *max_element(bloomDay.begin(), bloomDay.end());
    int mid = start + (end - start) / 2; // defines the no of days
    int ansy = -1;

    while (start <= end)
    {
        bool ans = findans(bloomDay, m, k, mid);

        if (ans == true)
        {
            ansy = mid;    // store the day number and check for more smaller day
            end = mid - 1; // it means that on right is possible check for lower on left
        }

        else
            start = mid + 1; // it means that at left also not possible go on right

        mid = start + (end - start) / 2;
    }
    return ansy;
    // can also return start,as initially the start was not possible but the end was,hence at last start would be pointing to the minimum possible
    // T.C- O(log(max_element-min_element+1)+N(for funcn loop))
}

int main()
{

    return 0;
}