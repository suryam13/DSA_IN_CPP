#include <bits/stdc++.h>
using namespace std;
// GFG
int search(int arr[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}

int main()
{

    return 0;
}