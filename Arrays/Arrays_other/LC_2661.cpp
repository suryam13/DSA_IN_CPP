#include <bits/stdc++.h>
using namespace std;
int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
{

    vector<int> row(mat.size());
    vector<int> col(mat[0].size());
    unordered_map<int, pair<int, int>> mapy;

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            mapy[mat[i][j]] = make_pair(i, j); // storing the postion of row and column for a particular value
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        auto pairy = mapy[arr[i]];
        row[pairy.first]++;
        col[pairy.second]++;

        // look if a column has to be full then it has to be equal to row size consider 2x3 matrix
        if (row[pairy.first] == col.size() || col[pairy.second] == row.size())
            return i; // means that entire row or entire column is filled
    }

    return 0;
}
int main()
{

    return 0;
}