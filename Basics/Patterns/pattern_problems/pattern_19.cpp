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

    for (int i = 0; i < 2 * n - 1; i++)
    {
        int stars = i + 1;

        if (i > n - 1)
            stars = 2 * n - i - 1;

        for (int i = 0; i < stars; i++)
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