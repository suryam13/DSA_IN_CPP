#include <bits/stdc++.h>
using namespace std;
//codestorywithmik
int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
{
    // constructing cumulative row sum for ease of calculation
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> prefixSumMat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += matrix[i][j];
            prefixSumMat[i][j] = sum;
        }
    }
    int cnt = 0;

    // fixing the start point column and making submatrices
    for (int startCol = 0; startCol < n; startCol++) // consider the start point of column
    {
        for (int col = startCol; col < n; col++) // start from that start point and continue going downwards for exploring each
        // row as submatrix
        {
            unordered_map<int, int> mapy;
            mapy[0] = 1;
            int sum = 0;
            for (int row = 0; row < m; row++)
            {
                sum += prefixSumMat[row][col] - (startCol > 0 ? prefixSumMat[row][startCol - 1] : 0);
                // when we are considering the start col as 1 or more than that we need to subtract the
                // sum of the just previous of startCol becuase now we are considering other
                // starting point of column that is submatrix so the cumulative sum would be subtracted

                // find in map just like leetcode 560
                int rem = sum - target;

                cnt += mapy[rem];

                mapy[sum]++;
            }

            // dont worry about each row starting as that is the reason why we too cumulative sum of row so that would
            // be covered in the column iteration when we are finding in map
        }
    }

    return cnt;
}

int main()
{

    return 0;
}