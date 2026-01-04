#include <bits/stdc++.h>
using namespace std;

/*
 pattern
1
1 2
1  3
1   4
12345

*/

void pattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i + 1; j++)
        {
            if (j == 0)
                cout << j + 1;

            else if (i == n - 1 && j < n)
                cout << j + 1;

            else if (j == i + 1 && i != 0 && i != n - 1)
                cout << i + 1;
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