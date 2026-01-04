#include <bits/stdc++.h>
using namespace std;

// DP problem,through recursion giving TLE(GFG)
// Pattern-Exploring all the possible ways

int maximizeTheCuts(int n, int x, int y, int z)
{
    if (n == 0)
        return 0; // means now more possible length could be cut

    if (n < 0)
        return INT_MIN; // so that this section is isnt conidered as not possible to make that particular cut successful

    int option1 = 1 + maximizeTheCuts(n - x, x, y, z);
    // solving for 1 case as cutting the length of 2 and identifying how many parts would be obtained finally through recursive calls
    int option2 = 1 + maximizeTheCuts(n - y, x, y, z);
    // similiar for y
    int option3 = 1 + maximizeTheCuts(n - z, x, y, z);
    // similiar for z

    int finalAns = max(option1, max(option2, option3));

    return finalAns;
}
int main()
{

    return 0;
}