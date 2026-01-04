#include <bits/stdc++.h>
using namespace std;

/*
rectangle pattern
*****
*****
*****
*/

void pattern(int x, int y)
{

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    int x;
    cout << "enter the value of x : ";
    cin >> x;

    int y;
    cout << "enter the value of y : ";
    cin >> y;

    pattern(x, y);
    return 0;
}