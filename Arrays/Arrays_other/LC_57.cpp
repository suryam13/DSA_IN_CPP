#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{

    vector<vector<int>> ans;
    bool check = 1;

    if (intervals.empty())
    {
        ans.push_back({newInterval[0], newInterval[1]});
        return ans;
    }

    // check for first interval whether it is smaller then the given new interval or not
    if (newInterval[0] <= intervals[0][0])
    {
        ans.push_back({newInterval[0], newInterval[1]});
        check = 0;
    }

    for (auto &vec : intervals)
    {
        int first = vec[0];
        int second = vec[1];

        if (ans.empty())
        {
            ans.push_back({first, second});
            continue;
        }

        else if (check && first > newInterval[0])
        { // means new interval is to be added here
            check = 0;

            if (ans.back()[1] >= newInterval[0])
            {
                ans.back()[1] = max(ans.back()[1], newInterval[1]);
            }

            else
            {
                ans.push_back({newInterval[0], newInterval[1]});
            }
        }

        // this has to be constant in every iteration
        if (ans.back()[1] >= first)
        {
            ans.back()[1] = max(ans.back()[1], second);
        }

        else
        {
            ans.push_back({first, second});
        }
    }

    // in case if all the intervals are been processed and this is the last one remaining
    if (check)
    {
        check = 0;

        if (ans.back()[1] >= newInterval[0])
        {
            ans.back()[1] = max(ans.back()[1], newInterval[1]);
        }

        else
        {
            ans.push_back({newInterval[0], newInterval[1]});
        }
    }
    return ans;
}
int main()
{

    return 0;
}