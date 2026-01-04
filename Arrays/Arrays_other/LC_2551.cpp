#include <bits/stdc++.h>
using namespace std;

long long putMarbles(vector<int> &weights, int k)
{

    // solved LC 2740,1877

    int n = weights.size();
    vector<int> pairSum;
    for (int i = 1; i < weights.size(); i++)
    {
        pairSum.push_back(weights[i] + weights[i - 1]);
    }

    // now depending upon the k size we have to form bags i.e. k-1
    sort(begin(pairSum), end(pairSum)); // to get the min first and max at last
    long long maxi = 0;
    long long mini = 0;
    long long ans = 0;
    for (int i = 0; i < k - 1; i++)
    {
        mini += pairSum[i];
        maxi += pairSum[n - i - 2];
    }

    ans = (maxi - mini);

    return ans;
}
int main()
{

    return 0;
}