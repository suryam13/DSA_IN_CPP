#include <bits/stdc++.h>
using namespace std;
// GFG
int largest(vector<int> &arr, int n)
{
    // T.C. O(N)
    //  int maxi=INT_MIN;

    //   for(int i=1;i<n;i++)
    //   {
    //      maxi=max(maxi,arr[i]);

    //   }
    //   return maxi;

    // requires O(N) time complexity
    int maxi = *max_element(arr.begin(), arr.end());
    return maxi;

    // bruteforce approach,gets solved in O(NlogN)
    //  sort(arr.begin(),arr.end(),greater<int>());
    //  return arr[0];
}
int main()
{

    return 0;
}