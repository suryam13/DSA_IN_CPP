#include <bits/stdc++.h>
using namespace std;

// brute approach is through o(N2) going and checking all the sum as in longest subarray sum
int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    // T.C-O(NLogN)
    // S.C-O(N)

    int prefixSum = 0;
    int count = 0;

    map<int, int> mapy;
    mapy[0] = 1; // to handle the case if 0 comes

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];

        int rem = prefixSum - k; // to check whether there exists rem value and yes than how many?

        // if(rem==0)
        // count++;

        count = count + mapy[rem]; // basically counting the occurence of rem

        mapy[prefixSum]++; // updating the count of sum upto a particular index
    }
    return count;
}
int main()
{

    return 0;
}