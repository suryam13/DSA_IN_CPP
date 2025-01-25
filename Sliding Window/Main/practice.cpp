#include <bits/stdc++.h>
using namespace std;
int constantWindow(vector<int> &v, int k, int maxi)
{
    int sum = 0;
    // finding out the initial window sum
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }

    int i = 1;
    int j = k;

    while (j < v.size())
    {
        maxi = max(maxi, sum);

        sum -= v[i - 1];
        sum += v[j];

        i++;
        j++;
    }
    return maxi;
}
int main()
{
    vector<int> v = {-1, 2, 3, 3, 4, 5, -1};
    int k = 4;
    int maxi = INT_MIN;

    cout<<constantWindow(v,k,maxi);

    return 0;
}