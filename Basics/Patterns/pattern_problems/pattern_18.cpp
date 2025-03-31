#include <bits/stdc++.h>
using namespace std;

/*
 pattern


********1********
*******2*2*******
******3*3*3******
*****4*4*4*4*****
****5*5*5*5*5****


*/

void pattern(int n)
{

    for (int i = 0; i < n; i++)
    {

        // for stars
        for (int j = 0; j < 2 * n - 2 - i; j++)
        {
            cout << "*";
        }

        // for figures
        for (int j = 0; j < 2 * i + 1; j++)
        {

            if (j % 2 == 0)
                cout << i + 1;

            else
            {
                cout << "*";
            }
        }

        // for stars
        for (int j = 0; j < 2 * n - 2 - i; j++)
        {
            cout << "*";
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