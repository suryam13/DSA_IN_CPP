#include <bits/stdc++.h>
using namespace std;
vector<int> decrypt(vector<int> &code, int k)
{

    // Using Sliding Window
    int n = code.size();
    vector<int> ans(n, 0);

    int i = -1;
    int j = -1;

    if (k == 0)
        return ans;

    else if (k > 0)
    {
        i = 1;
        j = k;
    }

    else
    { // means less than 0
        i = n - abs(k);
        j = n - 1;
    }

    long long sum = 0;

    for (int l = i; l <= j; l++)
    { // calculating the initial sum as we do for refernece
      // standard sliding window template
        sum = sum + code[l];
    }

    for (int k = 0; k < n; k++)
    { // inserting into the array that has to be returned
        ans[k] = sum;

        sum = sum - code[i % n]; // doing this as it has to be cyclic so if out of
                                 // bound then would be dealt through this
        i++;

        j++;
        sum = sum + code[j % n];
    }

    return ans;
}
int main()
{

    return 0;
}