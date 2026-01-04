#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long countPairs(vector<int> &nums, int k)
{
    unordered_map<int, int> mapy;
    ll cnt = 0;

    // initially i did the mod approach which gave tle used to store the
    // current mod with the k and then check for next mod divisiblility by
    // iterating in the map. but gcd is more suitable as it reduces the size
    // of map,gcd in worst case would store the divisors of k but mod would store every value from 0 to k-1,so thats the
    // optimisation required
    for (int &num : nums)
    {
        int gcd = __gcd(num, k); // gcd calculation

        for (auto &[r, freq] : mapy)
        {
            if ((gcd * 1LL * r) % k == 0)
            {
                cnt += freq;
            }
        }

        mapy[gcd]++;
    }

    return cnt;
}
int main()
{

    return 0;
}