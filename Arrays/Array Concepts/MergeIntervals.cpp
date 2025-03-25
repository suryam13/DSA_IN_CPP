#include <bits/stdc++.h>
using namespace std;

// LC-56
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // Standard merge interval pattern

    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    // sorting for ease in interval check,O(NlogN)
    // can be done without sorting too but would take O(N^2)as we have to make comparisons with each and every
    // ans and would have to compare start2<=end1 and start1<=end2

    ans.push_back(intervals[0]); // pushing first now start comparing

    for (int i = 1; i < intervals.size(); i++)
    {                                         // check the end of 1st and the start of 2nd if 2nd is less than or equal to then it lies in same interval
        if (ans.back()[1] >= intervals[i][0]) // then merge as it's overlapping consider the equal ones too
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);

        else
            ans.push_back(intervals[i]);
    }

    return ans;
}
int main()
{

    return 0;
}