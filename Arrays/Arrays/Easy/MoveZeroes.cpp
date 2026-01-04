#include <bits/stdc++.h>
using namespace std;

//LC-283
// mpove zeroes to right with maintaining order
void moveZeroes(vector<int> &arr)
{
    // //optimised through two pointer approach

    // //j will point to the index of 0

    int j = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return;

    // i will point to the index of num!=0
    for (int i = j + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    // brute force approach

    // storing num!=0
    //  vector<int> v;
    //  for(int i=0;i<arr.size();i++)
    //  {
    //      if(arr[i]!=0)
    //      v.push_back(arr[i]);
    //  }

    // for(int i=0;i<v.size();i++)
    // {
    //     arr[i]=v[i];
    // }

    // for(int i=v.size();i<arr.size();i++)
    // {
    //     arr[i]=0;
    // }
}

int main()
{

    return 0;
}