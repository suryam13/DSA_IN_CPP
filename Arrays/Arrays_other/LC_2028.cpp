#include <bits/stdc++.h>
using namespace std;

vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    vector<int> ans;

    // if(mean>rolls.size())
    // return ans;

    // calculating sum of main given array
    long long sum = 0;
    for (int i = 0; i < rolls.size(); i++)
    {
        sum = sum + rolls[i];
    }

    int x;

    x = (mean * (rolls.size() + n)) - sum;
    // derived from formulae sum+x/(m+n)=mean where x is the considered the
    // remaining part;

    while (n != 0)
    {
        int value = x / n;

        ans.push_back(value);

        x = x - value;
        n--;
    }

    for (auto it : ans)
    {
        if (it > 6 || it < 1)
            return {};
    }

    return ans;
}
int main()
{

    return 0;
}