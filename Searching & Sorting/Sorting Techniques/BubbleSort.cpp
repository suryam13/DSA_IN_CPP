#include <bits/stdc++.h>
using namespace std;
//T.C. O(N2) Worst Case O(N) Best Case (use isSwapped check)
void bubbleSort(vector<int> &arr)
{

    int i = arr.size() - 1;

    while (i >= 0)
    {
        bool isSwapped = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = 1;
            }
        }

        if (isSwapped == 0)
            break; // as there are no swaps so it is already sorted
        i--;
    }
}
int main()
{

    return 0;
}