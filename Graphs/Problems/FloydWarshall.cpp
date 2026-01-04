#include <bits/stdc++.h>
using namespace std;

//GFG
void floydWarshall(vector<vector<int>> &dist)
{
    // T.C. O(N^3)
    int n = dist.size();
    for (int via = 0; via < n; via++)
    {
        // now go through each via
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // handling the overflow condition if there is no path so please dont
                // explore as it could give undesired results
                if (dist[i][via] != 1e8 && dist[via][j] != 1e8)
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }
}
int main()
{

    return 0;
}