#include <bits/stdc++.h>
using namespace std;

/*
numeric half pyramid pattern
1
12
123
1234
12345
*/

void pattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
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