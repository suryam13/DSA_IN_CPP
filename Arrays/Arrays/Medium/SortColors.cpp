#include <bits/stdc++.h>
using namespace std;

// LC-75
/*
bruteforce approach-
sort the entire array
T.C. O(NlogN)

better
intilaize three variables for storing the count of 0,1,2,then place them
T.C. O(2N) one for traversing while counting while another for placing elemnets according to the count

optimal-use dutch national flag algorithm
takes O(N) in worst case
*/

void sortcolors(int arr[], int n)
{
    // dutch flag algorithm
    int left = 0;
    int right = n - 1;

    int index = 0;
    while (index <= right)
    {
        if (arr[index] == 0)
        {
            swap(arr[index], arr[left]);
            left++;
            index++;
        }

        else if (arr[index] == 1)
        {
            index++;
        }

        else if (arr[index] == 2)
        {
            swap(arr[right], arr[index]);
            right--;
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

    sortcolors(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i];
    }

    return 0;
}
