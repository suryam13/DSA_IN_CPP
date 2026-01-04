#include <bits/stdc++.h>
using namespace std;

/*
 pattern
    1
   121
  12321
 1234321
123454321

*/

void pattern(int n)
{

    for (int i = 0; i < n; i++)
    {

        // for spaces
        int count = i;
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // for figures
        for (int j = 0; j < 2 * i + 1; j++)
        {

            if (j <= i)
                cout << j + 1;

            else
            {
                cout << count;
                count--;
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