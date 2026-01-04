#include <bits/stdc++.h>
using namespace std;


int subarraysDivByK(vector<int> &nums, int k)
{
    // LETS SUPPOSE WE HAVE CURRENTLY SUM 11 AND NOW WE WISH TO KNOW WHETHER WE HAVE
    // SOMETHING LESS THAN THAT WHICH IS DIVISIBLE THAN THIS IN THE PAST SO HAVE TO
    // KEEP A TRACK OF THT USING HASHMAP + PREFIXSUM
    // for doing negative division just ignore nefative sign and then at last apply
    //-ve sign

    // -1 1
    unordered_map<int, int> mapy;
    mapy[0] = 1; // storing 0 remainder prior
    int n = nums.size();
    long long sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        int mody = sum % k; // required mod
        if (mody < 0)
            mody += k; // for converting negative mod to +ve
        cnt += mapy[mody];
        mapy[mody]++;
    }

    return cnt;
}
int main()
{

    return 0;
}