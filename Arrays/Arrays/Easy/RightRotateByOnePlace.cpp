#include <bits/stdc++.h>
using namespace std;
// LC-189
void rotate(vector<int> &arr, int k)
{

    int n = arr.size();
    k = k % n;
    // 1st approach by reversing
    reverse(arr.begin() + n - k, arr.end());   // last d elements
    reverse(arr.begin(), arr.begin() + n - k); // first elements
    reverse(arr.begin(), arr.end());

    // 2nd approach
    //   int n=arr.size();
    //  vector<int> ans(n);
    //  for(int index=0;index<arr.size();index++)
    //  {
    //      int newIndex=(index+k)%n;
    //      ans[newIndex]=arr[index];
    //  }
    //  arr=ans;

    // 3rd approach
    //  int n=arr.size();
    //  k = k % n; // for getting exact rotations
    //  // storing last two values
    //  int* temp = new int[k];
    //  for (int i = 0; i < k; i++) {
    //      temp[i] = arr[n - i - 1];
    //  }

    // // shifting values
    // for (int i = n - 1; i >= k; i--) {
    //     arr[i] = arr[i - k];
    // }

    // // putting the values again at first after rotation
    // for (int i = 0; i < k; i++) {
    //     arr[i] = temp[k - 1 - i];
    // }

    // 4th approach
    // apply loop on right rotate by one place till k times
}

int main()
{

    return 0;
}