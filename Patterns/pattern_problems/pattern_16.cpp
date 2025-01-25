#include <bits/stdc++.h>
using namespace std;

/*
 pattern
12345
2  5
3 5
45
5

*/

void pattern(int n)
{
    char temp;
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j <= n; j++)
        {
            if (i == 0)
                cout << j;

            else if (j == i + 1 || j == n)
                cout << j;

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