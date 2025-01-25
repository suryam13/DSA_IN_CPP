#include <bits/stdc++.h>
using namespace std;

// with maintainig the original order,push to left

void pushZerosToEnd(int arr[], int n)
{

    // for determining the position of 1st negative
    // or can use dutch national flag algorithm but order would vary
    int j = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] < 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return;

    for (int i = j - 1; i >= 0; i--)
    {
        if (arr[i] >= 0)
        {
            swap(arr[i], arr[j]);
            j--;
        }
    }
}

int main()
{
    int arr[6];
    cout << "enter array elements : ";

    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }

    pushZerosToEnd(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
