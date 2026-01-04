#include <bits/stdc++.h>
using namespace std;

// i have to start from jth index and look if the j-1 is bigger and if it is then pls swap

// T.C. O(N2) Worst Case O(N) Best Case (use isSwapped check)

void insertionSort(vector<int> &arr)
{

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) // pls swap
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }

    // the worst case tc would be O(n2) when the array is fully unsorted like if it is in the descending order
    // the best case tc would be o(n) as when the array is fully sorted like if it is it the ascending order
}
int main()
{

    return 0;
}