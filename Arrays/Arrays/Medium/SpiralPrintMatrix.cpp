#include <bits/stdc++.h>
using namespace std;

// only possible solution
// T.C. O(nxm) as u are indirectly iterating all the elements

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    vector<int> ans;

    int m = matrix.size();    // row size
    int n = matrix[0].size(); // col size

    int left = 0;       // col side 1st 0
    int right = n - 1;  // col side last
    int top = 0;        // row side 1st 0
    int bottom = m - 1; // row side last

    while (left <= right && top <= bottom)
    // untill there is 1 and until there is 1 row
    {
        // will go from left to right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
            // as row is constant so will consider top
        }
        top++; // to move one step down

        // will go from top to bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
            // as column is constant so will consider right
        }
        right--; // to move one step back from right

        if (top <= bottom) // to manage single row case to not consider
                           // right to left reverse
        {                  // will go from right to left
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
                // as row is contsant so will consider bottom
            }
            bottom--; // to move bottom one step up
        }

        if (left <= right)
        { // will go from bottom to top
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
                // as column is constant so we will consider left
            }
            left++;
        }
    }

    return ans;
}

// approach 2

// int m = MATRIX.size();    // row size
// int n = MATRIX[0].size(); // col size;
// vector<int> ans;          // for storing the answer

// int left = 0;
// int right = n - 1;
// int top = 0;
// int bottom = m - 1;

// int total = m * n; // total no of iterations that i have to perform
// int count = 0;     // to store the number of iterations as we proceed

// while (count < total)
// {
//     // from left to right
//     for (int i = left; i <= right && count < total; i++)
//     {
//         ans.push_back(MATRIX[top][i]);
//         count++;
//     }
//     top++;

//     // from top to bottom
//     for (int i = top; i <= bottom && count < total; i++)
//     {
//         ans.push_back(MATRIX[i][right]);
//         count++;
//     }
//     right--;

//     // from right to left
//     for (int i = right; i >= left && count < total; i--)
//     {
//         ans.push_back(MATRIX[bottom][i]);
//         count++;
//     }
//     bottom--;

//     // from bottom to top
//     for (int i = bottom; i >= top && count < total; i--)
//     {
//         ans.push_back(MATRIX[i][left]);
//         count++;
//     }
//     left++;
// }

// return ans;

int main()
{

    return 0;
}