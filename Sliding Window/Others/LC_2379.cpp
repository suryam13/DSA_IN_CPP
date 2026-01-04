#include <bits/stdc++.h>
using namespace std;

int minimumRecolors(string blocks, int k)
{

    int whiteBalls = 0;
    int minRecolors = INT_MAX;

    for (int i = 0; i < k; i++)
        if (blocks[i] == 'W')
            whiteBalls++;

    if (whiteBalls < minRecolors)
        minRecolors = whiteBalls;

    int j = k - 1;
    int i = 0;

    while (j + 1 < blocks.size())
    {
        if (blocks[i] == 'W')
            whiteBalls--;

        i++;

        j++;

        if (blocks[j] == 'W')
            whiteBalls++;

        minRecolors = min(minRecolors, whiteBalls);
    }

    return minRecolors;
}
int main()
{

    return 0;
}