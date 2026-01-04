#include <bits/stdc++.h>
using namespace std;

// MERGE INTERVAL PATTERN
int helper(vector<pair<int, int>> &v)
{
    vector<pair<int, int>> ans;

    ans.push_back(v[0]); // pushing first now start comparing

    for (int i = 1; i < v.size(); i++)
    {
        if (ans.back().second > v[i].first) // then please merge as it is overlapping
            ans.back().second = max(ans.back().second, v[i].second);

        else
            ans.push_back(v[i]);
    }

    return ans.size();
}
bool checkValidCuts(int n, vector<vector<int>> &rectangles)
{

    // Merge Interval Pattern
    // We are asked to cut along x or y axis
    // Cutting on x axis means check if there is enough distance to make two cuts that is check how many
    // different intervals can be made, similiarly on y axis check the x cordinates intervals
    // if more than or equal to 3 then true else false

    // bifurcating into x and y axis co-ordinates
    vector<pair<int, int>> xCord;
    vector<pair<int, int>> yCord;

    for (auto &rect : rectangles)
    {
        xCord.push_back({rect[0], rect[2]}); // x-axis
        yCord.push_back({rect[1], rect[3]}); // y-axis
    }

    // sorting for ease in interval check,O(NlogN)
    sort(xCord.begin(), xCord.end());
    sort(yCord.begin(), yCord.end());

    int cntX = helper(xCord);
    if (cntX >= 3)
        return true;
    int cntY = helper(yCord);
    if (cntY >= 3)
        return true;

    return false;
}
int main()
{

    return 0;
}