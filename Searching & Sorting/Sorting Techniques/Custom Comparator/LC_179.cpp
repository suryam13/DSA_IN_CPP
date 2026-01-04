#include <bits/stdc++.h>
using namespace std;
string largestNumber(vector<int> &nums)
{

    auto mycomparator = [](int &a, int &b) // lambda comparator
    {
        string aa = to_string(a);
        string bb = to_string(b);

        if (aa + bb > bb + aa)
            return true;

        return false;
    };

    sort(nums.begin(), nums.end(), mycomparator);

    if (nums[0] == 0)
        return "0";

    string ans = "";
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans + to_string(nums[i]);
    }

    return ans;
}
int main()
{

    return 0;
}