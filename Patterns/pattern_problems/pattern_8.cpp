#include <bits/stdc++.h>
using namespace std;

/*
inverted hollow half pyramid pattern
*****
*  *
* *
**
*
*
*/

void pattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (i == 0 || j == 0 || j == n - i - 1)
                cout << "*";

            else
                cout << " ";
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