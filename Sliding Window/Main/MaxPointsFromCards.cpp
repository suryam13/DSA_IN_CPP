#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{

    // using sliding window two pointer
    // we are said that we can either take from backwards or front but not
    // from middle as it should be contiguous
    long long sum = 0;
    long long maxi = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        sum += cardPoints[i];
    }

    if (k == cardPoints.size())
        return sum;

    int i = k - 1;
    int j = cardPoints.size() - 1;

    while (i >= 0)
    {
        maxi = max(maxi, sum);
        sum -= cardPoints[i];
        sum += cardPoints[j];

        i--;
        j--;
    }
    maxi = max(maxi, sum); // checking again because it wouldnt perform this
                           // operation from last turn so doing it here.
    return maxi;
}
int main()
{

    return 0;
}