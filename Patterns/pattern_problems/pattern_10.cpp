#include <bits/stdc++.h>
using namespace std;

/*
hollow full pyramid pattern

    *
   * *
  *   *
 *     *
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
                if (k == 0 || k == 2 * i || i == n - 1)
                    cout << "*";

                else
                {
                    cout << " ";
                }

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

        for (int j = 0; j < 2 * n - 1; j++)
        {

            if (i == n - 1)
            {
                cout << "*";
            }

            else if (j == n - i - 1 || j == n + i - 1)
            {
                cout << "*";
            }

            else
            {
                cout << " ";
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

    // pattern(n);
    alternatemethod(n);
    return 0;
}