#include <bits/stdc++.h>
using namespace std;

/*
 pattern
A
ABA
ABCBA
ABCDCBA
ABCDEDCBA

*/

void pattern(int n)
{
    char temp;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < 2 * i + 1; j++)
        {

            char ch = 'A' + j;

            if (j <= i)
            {
                cout << ch;
                if (j == i - 1)
                    temp = ch;
            }

            else
            {

                cout << temp;
                temp--;
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