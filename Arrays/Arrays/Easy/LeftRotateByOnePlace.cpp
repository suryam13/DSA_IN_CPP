#include <bits/stdc++.h>
using namespace std;
// coding ninja
//  left rotate by one place
vector<int> rotateArray(vector<int> &arr, int n)
{
    // T.C. O(N)
    //     rotate(arr.begin(),arr.begin()+1,arr.end());
    //   return arr;

    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    return arr;
}

// left rotate by d places

vector<int> rotateArray(vector<int> arr, int k)
{

    // method-1
    // T.C. O(n)
    //   k=k%arr.size();

    // reverse(arr.begin(),arr.begin()+k);
    //  reverse(arr.begin()+k,arr.end());
    //   reverse(arr.begin(),arr.end());

    // method 2
    // T.C.-->d + n-d +d -->O(n-d)
    int n = arr.size();
    k = k % n; // for getting exact number of rotations

    // storing first k values to as it would be left rotated
    int *temp = new int[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i]; // O(d)
    }

    // shifting values
    for (int i = k; i < n; i++)
    {

        arr[i - k] = arr[i]; // O(n-d)
    }

    // putting the values again at first after rotation
    int y = 0;
    for (int i = n - k; i < n; i++)
    {
        // arr[i] = temp[i+k-n]; //can use this to avoid extra y variable
        arr[i] = temp[y]; // O(n-(n-d))-->O(d)
        y++;
    }

    //  vector<int> arrr(arr);

    // method 3 apply for loop on rotate by one place till k to discard extra space but would take complexity(O(k^2))

    return arr;
}
int main()
{

    return 0;
}