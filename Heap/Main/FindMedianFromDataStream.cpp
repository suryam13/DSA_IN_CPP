#include <bits/stdc++.h>
using namespace std;

//LC - 295
class MedianFinder
{
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    // the point is that either both of them store equal amount of elements
    // or the left one should have only more than that of right side.

    MedianFinder() {}

    void addNum(int num)
    {

        if (leftMaxHeap.empty() || num < leftMaxHeap.top())
            leftMaxHeap.push(num);

        else // this heap is for the ones greater than top of leftMaxHeap
            rightMinHeap.push(num);

        // now i want to make sure that if the size of both of them are not
        // equal then left side should contain an element extra from the right
        // one means it shouldnt be like the left one contains more than one
        // elements tha that of right side
        if (leftMaxHeap.size() > rightMinHeap.size() + 1)
        {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }

        // right side should be strictly less than or equal to not greater than
        else if (rightMinHeap.size() > leftMaxHeap.size())
        {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }

    double findMedian()
    {

        double val;
        if (leftMaxHeap.size() == rightMinHeap.size())
            val = (double)(leftMaxHeap.top() + rightMinHeap.top()) / 2;

        else
            val = leftMaxHeap.top();

        return val;
    }
};
