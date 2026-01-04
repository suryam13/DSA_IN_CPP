#include <bits/stdc++.h>
using namespace std;

bool canArrange(vector<int> &arr, int k)
{

    unordered_map<int, int> mapy;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // int mody = arr[i] % k;
        int mody = ((arr[i] % k) + k) % k; // for -ve conversion

        if (mody == 0)
        {
            if (mapy[mody] > 0)
            {
                mapy[mody]--;
                cnt++;
            }

            else
                mapy[mody]++;
        }

        // cout<<mody<<endl;

        else if (mapy[mody] > 0) // means exists
        {
            cout << i << " " << mody << endl;
            cnt++;
            mapy[mody]--;
        }

        else // doesnt exist so add what we require i.e. k-remainder
        {
            int rem = k - mody;
            mapy[rem]++;
        }
    }

    // cout<<cnt;

    if (cnt == (arr.size() / 2))
        return true;

    return false;
}
int main()
{

    return 0;
}