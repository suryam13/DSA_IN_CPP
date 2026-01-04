#include <bits/stdc++.h>
using namespace std;

int pivotIndex(int arr[], int n)
{

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (start == end)
        {
            // single element
            return start;
        }

        else if ((mid + 1 < n) && (arr[mid] > arr[mid + 1]))
        {
            return mid;
        }

        else if ((mid - 1 >= 0) && (arr[mid] < arr[mid - 1]))
        {
            return mid - 1;
        }

        else if (arr[mid] >= arr[0])
        {
            start = mid +
                    1;
            // if this is to be written at last then no need of =
            // sign write directly in else part,problem arises when
            // there is 1,3 error is generated hence = is used
        }

        else if (arr[mid] < arr[0])
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return mid;
}
int findKRotation(int arr[], int n)
{
    // code here
    int ans = pivotIndex(arr, n);

    if (ans == n - 1)
    {
        return 0;
    }

    else
        return ans + 1;
}
int main()
{

    return 0;
}