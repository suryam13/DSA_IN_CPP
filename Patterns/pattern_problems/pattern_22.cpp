#include <bits/stdc++.h>
using namespace std;

/*
 pattern

*
**
***
****
***
**
*


*/

void pattern(int n)
{
    int count = 1;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int stars = 2*i + 1;

        if (i > n - 1)
            stars = 2 * n - i - 1;

        for (int j = 0; j < stars; j++)
        {
            if (j % 2 == 0)
            {
                cout << count;
                count++;
            }

            else
            {
                cout << "*";
            }
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cout << "enter the value of n : ";
    cin >> n;

    pattern(n);
    return 0;
}