#include <bits/stdc++.h>
using namespace std;
long long maxMatrixSum(vector<vector<int>> &matrix)
{

    // firstly we will have to calcualte thr maxSum possible

    long long sum = 0;
    int countNeg = 0; // to count the negative numbers
    int minVal = INT_MAX;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            sum = sum + abs(matrix[i][j]);
            // to keep track of min value so as to transfer to it in odd
            // case
            minVal = min(minVal, abs(matrix[i][j]));
            if (matrix[i][j] < 0)
                countNeg++;
        }
    }

    // means odd so by observation just deduct the minNeg so as to make the
    // sum greatest possible as there would always be atleast one negative
    // value so pass to the minimum one
    if (countNeg & 1)
        sum -= (2 * minVal);
    // multiplying by twice because we added in the sum earlier

    return sum;
}
int main()
{

    return 0;
}