#include <bits/stdc++.h>
using namespace std;

//LC - 347
vector<int> topKFrequent(vector<int> &nums, int k)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>> pq; // max heap

    unordered_map<int, int> mapy;

    for (auto &el : nums)
        mapy[el]++;

    for (auto & it : mapy)
        pq.push({it.second, it.first});

    vector<int> ans;

    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}
int main()
{

    return 0;
}