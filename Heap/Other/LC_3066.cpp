#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {

        int ans = 0;
        priority_queue<long, vector<long>, greater<long>> minHeap(nums.begin(), nums.end());
        // note when we push all the elements in one go then it takes O(logN) as it calls Heapify,else if u keep
        // on adding one by ine then it sould take logN for insertion and N for traversal on vector

        int opr = 0;
        while (minHeap.top() < k && minHeap.size() > 1)
        {
            long ele1 = minHeap.top(); // minimum element
            minHeap.pop();
            long ele2 = minHeap.top(); // maximum element
            minHeap.pop();

            opr++;

            long to_add = ele1 * 2 + ele2;
            minHeap.push(to_add);
        }

        return opr;

        return ans;
    }
};
int main()
{

    return 0;
}