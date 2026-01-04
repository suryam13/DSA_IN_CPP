#include <bits/stdc++.h>
using namespace std;
///SHEET : GFG
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    // write your code here

    vector<int> ans;

    int cnt = 0;
    for (auto &it : indices)
    {
        cnt = 0;
        for (int i = it + 1; i < arr.size(); i++)
        {
            if (arr[i] > arr[it])
                cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}
int main()
{

    return 0;
}