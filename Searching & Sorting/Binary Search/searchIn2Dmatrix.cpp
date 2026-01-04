#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int row = matrix.size();
    int col = matrix[0].size();
    int n = row * col;

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int rowIndex = mid / col;  //to extract the ith index in 2D array from linear array
        int colIndex = mid % col;
        cout << rowIndex << " " << colIndex;
        int currentNum = matrix[rowIndex][colIndex];

        if (currentNum == target)
            return true;

        else if (currentNum > target)
            end = mid - 1;

        else
            start = start + 1;

        mid = start + (end - start) / 2;
    }
    return false;
}
int main()
{

    return 0;
}