#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &ranks, int cars, long long mid)
{
    long long cntCars = 0;

    for (int i = 0; i < ranks.size(); i++)
    {
        // find out under 'mid' mins how many cars can the ith mechanic repair ?
        cntCars += sqrt(mid / ranks[i]); // since rank[i]*n*n(number of cars)=time consumed
        // so we want to figure out the number of cars sqrt(n)=time consumed/ranks[i]
    }

    if (cntCars >= cars) // means able to repair that many cars in that time
        return true;

    return false;
}
long long repairCars(vector<int> &ranks, int cars)
{

    int mini = *min_element(begin(ranks), end(ranks));
    long long result = 0;

    long long left = 0;
    long long right = (cars * 1LL * cars) * mini;
    long long mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (possible(ranks, cars, mid))
        {
            // then check for more minimum, but store the result as of now
            result = mid;
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }
    }
    return result;
}
int main()
{

    return 0;
}