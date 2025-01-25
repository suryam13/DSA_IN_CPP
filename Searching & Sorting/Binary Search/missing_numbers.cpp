#include <bits/stdc++.h>
using namespace std;

// eg numbers are from 1 to n
// but in i/p given from 1 till n-1
// eg 1 2 3 4 5     6 is missing
// eg 1 2 3 5 6  4 is missing

int missing(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == mid + 1)
            s = mid + 1;

        else if (arr[mid] != mid + 1)
        {
            ans = arr[mid];
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    if (ans == -1)
        return n + 1;

    return ans - 1;
}
int main()
{
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};
    cout << missing(arr, n);
    return 0;
}