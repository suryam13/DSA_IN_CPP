#include <bits/stdc++.h>
using namespace std;

/*
 floyd's pattern

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21


*/

void pattern(int n)
{
    int count = 1;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {
            cout << count<< " ";
            count++;
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