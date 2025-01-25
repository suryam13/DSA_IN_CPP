#include <bits/stdc++.h>
using namespace std;

/*
 full pyramid pattern

    *
   ***
  *****
 *******
*********
*/

void alternatemethod(int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (j < n - i - 1)
                cout << " ";

            else if (k < 2 * i + 1)
            {
                cout << "*";
                k++;
            }

            else
                cout << " ";
        }
        cout << endl;
    }
}

void pattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        // for spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // for stars
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // for spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }    //this step is optional,if commented would still work fine
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "enter the value of n : ";
    cin >> n;

    // pattern(n);
    alternatemethod(n);
    return 0;
}