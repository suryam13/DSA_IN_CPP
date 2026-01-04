#include <bits/stdc++.h>
using namespace std;

//with maintainig the original order

void pushZerosToEnd(int arr[], int n)
{

    // for determining the position of 1st zero
    int j = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return;

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{

    return 0;
}
