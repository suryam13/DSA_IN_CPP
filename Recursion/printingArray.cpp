#include <bits/stdc++.h>
using namespace std;

void printing(int arr[], int n)
{
    if (n == 0)
        return; // base case

    printing(arr, n - 1);      // recursive call
    cout << arr[n - 1] << " "; // processing at last means head recursion
}

void printing1(int arr[], int n) // printing array
{
    if (n == 0)
        return;

    cout << *arr << " ";
    printing1(arr + 1, n - 1);
}

int search(int arr[], int key, int n) // search in array
{
    if (n == 0)
        return -1;
    // base case

    if (arr[n - 1] == key)
        return n - 1;

    search(arr, key, n - 1);
}

void minimum(int arr[], int n, int &mini) // min in array
{

    // base case
    if (n == 0)
        return;

    mini = min(arr[n - 1], mini);

    minimum(arr, n - 1, mini);
}

void convert(int arr[], int n, vector<int> &ans) // even check
{
    if (n == 0)
        return;

    if (arr[n - 1] % 2 == 0)
        ans.push_back(arr[n - 1]);

    convert(arr, n - 1, ans);
}

void doubling(int arr[], int n) //doubling each element in the array
{
    if (n == 0)
        return;

    arr[n - 1] = 2 * arr[n - 1];

    doubling(arr, n - 1);
}

void printIndex(int arr[], int key, int n) // print positions of all keys where it is present
{
    if (n == 0)
        return;
    // base case

    if (arr[n - 1] == key)
        cout << n - 1 << " ";

    printIndex(arr, key, n - 1);
}
int main()
{
    // int arr[] = {1, 3, -1280, 5, 9};
    // // printing1(arr, 5);
    // // cout<<search(arr,7,5);
    // int mini = INT_MAX;
    // minimum(arr, 5, mini); //make sure mini is been sent as pass by reference else copy would be created
    // cout<<mini;

    // int arr[5]={2,4,6,9,8};

    // vector<int> ans;

    // convert(arr,5,ans);

    // for(auto it:ans)
    // {
    //     cout<<it<<" ";
    // }

    int arr[5] = {2, 4, 6, 4, 4};
    printIndex(arr, 4, 5);

    return 0;
}