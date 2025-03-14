#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int> &candies, long long k, int assumed)
{
    long long sum = 0;

    for (int i = 0; i < candies.size(); i++)
    {
        sum += (candies[i] / assumed);

        if (sum >= k)
            return true; // means possible to distribute this number of candies to each as they fulfill
    }
    return false;
}
int maximumCandies(vector<int> &candies, long long k)
{

    int max = *max_element(candies.begin(), candies.end()); // at max this can be given

    int start = 1; // at min 1 candies can be given to each children
    int end = max;
    int mid;
    int freq = 0;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (valid(candies, k, mid)) // means possible to distribute this amount of candies to children
        {
            start = mid + 1;
            freq = mid;
        }

        else
            end = mid - 1;
    }

    return freq;
}
int main()
{

    return 0;
}