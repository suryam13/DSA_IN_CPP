#include <bits/stdc++.h>
using namespace std;
// DIFFERENCE ARRAY TECHNIQUE

bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{

    // differnece array technique

    vector<int> diffArray(nums.size(), 0);

    for (auto &query : queries)
    {
        int i = query[0];
        int j = query[1];

        diffArray[i] -= 1; // adding -1 at the start idx  +(-1) == -1
        if (j + 1 < nums.size())
            diffArray[j + 1] += 1; // subtracting -1 at the last idx + 1 if it exists  -(-1) == +1
    }

    // cumulative sum
    for (int i = 1; i < diffArray.size(); i++)
    {
        diffArray[i] = diffArray[i - 1] + diffArray[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] + diffArray[i]) > 0) // means not possible to transform it into zero
            return false;
    }
    return true;
}
int main()
{

    return 0;
}