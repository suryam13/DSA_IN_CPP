#include <bits/stdc++.h>
using namespace std;

/*
combined pattern

***** *****
****   ****
***     ***
**       **
*         *
*         *
**       **
***     ***
****   ****
***** *****

*/

void pattern_1(int n)
{

    for (int i = 0; i < n; i++)
    {
        // for stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        // for spaces
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << " ";
        }

        // for stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}
void pattern_2(int n)
{

    for (int i = 0; i < n; i++)
    {
        // for stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        // for spaces
        for (int j = 0; j < 2 * n - 2 * i - 1; j++)
        {
            cout << " ";
        }

        // for stars
        for (int j = 0; j <= i; j++)
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

    pattern_1(n);
    pattern_2(n);

    return 0;
}