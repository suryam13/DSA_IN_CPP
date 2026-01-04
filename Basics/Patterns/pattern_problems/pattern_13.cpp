#include <bits/stdc++.h>
using namespace std;

/*
 pattern
1
2*2
3*3*3
4*4*4*4

*/

void pattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j % 2 == 0)
                cout << i + 1;

            else
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