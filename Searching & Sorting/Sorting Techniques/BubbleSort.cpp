#include <bits/stdc++.h>
using namespace std;


// what bubble sort tells is that bubble ahead the greater element as last as possible by making consecutive comparisons
// and then shrink the window size by 1 and then again repeat the same process

// T.C. O(N2) Worst Case
// T.C. O(N) Best Case (use isSwapped check) 

// worst case tc would be o(N2)
// best case if we add a check that if there are no swaps made within a range then we can stop the loop
// this case would be when a range is sorted 
// eg - if the array is in ascending order only then no swaps made so o(n) 


void bubbleSort(vector<int> &arr)
{

    int i = arr.size() - 1; // initial window

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
        i--;       // shrink the window size by 1
    }
}
int main()
{

    return 0;
}