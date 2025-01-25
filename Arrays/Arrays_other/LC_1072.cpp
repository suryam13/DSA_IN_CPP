#include <bits/stdc++.h>
using namespace std;
int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
{
    // got the pattern that ones with same row or inverted row would be od
    // max count

    unordered_map<string, int> mapy;

    for (auto &row : matrix)
    {
        string pattern = "";

        int firstCol = row[0];
        for (auto &it : row) // this is for detection of inverse row so
                             // traversing through current row
        {
            if (it == firstCol)
                pattern += 'S'; // same

            else
                pattern += 'N'; // not same
        }
        mapy[pattern]++;
    }

    int maxVal = 0;
    // the one whose pattern is max would get stored
    // for (auto &[key, value] : mapy)
    // {
    //     maxVal = max(maxVal, value);
    // }
    for (auto it : mapy)
    {
        maxVal = max(maxVal, it.second);
    }

    return maxVal;
}
int main()
{

    return 0;
}