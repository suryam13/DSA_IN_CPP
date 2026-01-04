#include <bits/stdc++.h>
using namespace std;
// LC-860

bool lemonadeChange(vector<int> &bills)
{

    int x = 0; // count of 5$
    int y = 0; // count of 10$
    for (auto it : bills)
    {
        if (it == 5)
            x++;

        else if (it == 10)
        {
            y++;
            if (x > 0)
                x--;

            else
                return false;
        }

        else // it==20
        {
            int req = 15;
            if (y > 0)
            { // for the case if we have 10$ then
                y--;
                req = req - 10;
            }

            if (x >= (req / 5))
            { // for the casee if we dont have any 10$
              // we have 5$ only
                x = x - (req / 5);
            }

            else
                return false;
        }
    }
    return true;
}
int main()
{

    return 0;
}