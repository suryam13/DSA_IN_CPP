#include <bits/stdc++.h>
using namespace std;
//TC-O(N2) to be accurate it would be sum of n elements i.e. n*n+1/2-->n2
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