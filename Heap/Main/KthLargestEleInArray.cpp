#include <bits/stdc++.h>
using namespace std;
// LC - 215

int findKthLargest(vector<int> &nums, int k)
{

    priority_queue<int, vector<int>> pq(nums.begin(), nums.end());
    // just takes O(N) due to the concept of heapify

    while (k--)
    {
        if (k == 0)
            return pq.top();
        pq.pop();
    }

    return 0;
}

int main()
{

    return 0;
}