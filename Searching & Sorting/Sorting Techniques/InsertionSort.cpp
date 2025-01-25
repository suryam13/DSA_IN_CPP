#include <bits/stdc++.h>
using namespace std;
// T.C. O(N2) Worst Case O(N) Best Case (use isSwapped check)

void insertionSort(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
int main()
{

    return 0;
}