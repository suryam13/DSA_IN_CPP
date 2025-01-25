#include <bits/stdc++.h>
using namespace std;

// bruteforce approach to use two loops and check for sum
bool keypair(int arr[], int n, int target)
{
    //O(NlogN)
    sort(arr, arr + n);
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return 1;

        else if (sum < target)
        {
            left++;
        }

        else if (sum > target)
        {
            right--;
        }
    }
    return 0;
}

int main()
{

    return 0;
}