#include <bits/stdc++.h>
using namespace std;

// LC - 721 Sheet
class Solution
{
public:
    vector<int> parent;

    int find(int ele)
    {
        if (ele == parent[ele])
            return ele;

        return parent[ele] = find(parent[ele]);
    }

    void Union(int ele1, int ele2)
    {
        int find1 = find(ele1);
        int find2 = find(ele2);

        if (find1 != find2)
        {
            parent[find1] = find2;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {

        int n = accounts.size();
        vector<vector<string>> ans;
        parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        map<string, int> mapy;
        // email to idx linakge

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mapy.find(accounts[i][j]) == mapy.end())
                    mapy[accounts[i][j]] = i;

                else
                    Union(i, mapy[accounts[i][j]]);
            }
        }

        unordered_map<int, vector<string>> finalMapping;

        // for (auto &[key, value] : mapy)
        // {
        //     int findPar = find(value);
        //     finalMapping[findPar].push_back(key);
        // }

        // for (auto &[key, value] : finalMapping)
        // {
        //     vector<string> dummy;
        //     dummy.push_back(accounts[key][0]);
        //     for (auto &str : value)
        //     {
        //         dummy.push_back(str);
        //     }

        //     ans.push_back(dummy);
        // }

        return ans;
    }
};
int main()
{

    return 0;
}