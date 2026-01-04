#include <bits/stdc++.h>
using namespace std;
// TC-O(N2) to be accurate it would be sum of n elements i.e. n*n+1/2-->n2
void selectionSort(vector<int> &arr)
{

    // get minimum
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minInd = i;

        for (int j = i; j < arr.size(); j++)
        {
            if (arr[j] < arr[minInd])
                minInd = j;
        }
        swap(arr[i], arr[minInd]);
    }
}
int main()
{

    return 0;
}

/*
Time complexity describes how the number of operations performed by an algorithm grows as the input size grows.
It does not measure actual execution time in seconds; instead, it measures the order of growth of operations.

For example, if an algorithm has a time complexity of O(n²) and the input size n is 10⁴, then the total number of operations will be approximately (10⁴)² = 10⁸.

Now, if a certain execution environment or process has a fixed limit of 10⁴ operations per second, then executing 10⁸ operations would take:
10⁸ ÷ 10⁴ = 10⁴ seconds
*/