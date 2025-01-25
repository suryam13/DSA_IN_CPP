#include <bits/stdc++.h>
using namespace std;

int chalkReplacer(vector<int> &chalk, int k)
{

    long long sum = 0;
    for (int i = 0; i < chalk.size(); i++)
    {
        sum += chalk[i];
    }

    int new_k = k % sum; // to reduce the number of rounds to performed and eliminating the need of two loops

    for (int i = 0; i < chalk.size(); i++)
    {
        if (chalk[i] > new_k)
            return i;

        new_k -= chalk[i];
    }
    return 0;
}

int main()
{

    return 0;
}