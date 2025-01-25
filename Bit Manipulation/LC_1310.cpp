#include <bits/stdc++.h>
using namespace std;
vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{

    // T.C O(Q*N)  //q is queries and n is size of the array
    //  vector<int> v;
    //  int ans = 0;
    //  for (auto it : queries) {
    //      int start = it.front();
    //      int end = it.back();

    //     for (int i = start; i <= end; i++) {
    //         ans = ans ^ arr[i];
    //     }
    //     v.push_back(ans);
    //     ans = 0;
    // }
    // return v;

    // using bit manipulation,storing cumulative xor
    // T.C O(N+Q) //S.C. O(1)
    vector<int> xorAns(arr.size(), 0);
    xorAns[0] = arr[0];
    vector<int> v;

    for (int i = 1; i < arr.size(); i++)
    {
        xorAns[i] = xorAns[i - 1] ^ arr[i];
    }

    for (auto it : queries)
    {
        int start = it[0];
        int end = it[it.size() - 1];

        if (start == 0)
            v.push_back(xorAns[end]);

        else
        {
            int ans = xorAns[start - 1] ^ xorAns[end];
            v.push_back(ans);
        }
    }
    return v;
}
int main()
{

    return 0;
}