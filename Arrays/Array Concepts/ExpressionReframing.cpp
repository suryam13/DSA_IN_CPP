#include <bits/stdc++.h>
using namespace std;
//LC 2364
long long countBadPairs(vector<int> &nums)
{

    // always when u get relations like this try to reframe it
    //j - i != nums[j] - nums[i]
    // nums[i]-i!=nums[j]-j is considered to be a bad pair

    long long badPairs = 0;
    unordered_map<int, int> mapy; // stores the values and how many times it occured

    for (int i = 0; i < nums.size(); i++)
    {
        // find whether this nnumber has repeated before if yes then how many times
        int opr = nums[i] - i;    // current operation
        int findPrev = mapy[opr]; // how may times occured? if entry is not then automatically 0

        badPairs += i - findPrev; // i resembles how many distance is passed means that many bad pairs -(minus) the times the
        // the same number has occured previously as it wont make a bad pair

        mapy[opr]++;
    }
    return badPairs;

    return 0;
}
int main()
{

    return 0;
}