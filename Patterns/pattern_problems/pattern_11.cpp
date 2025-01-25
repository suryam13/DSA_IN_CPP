#include <bits/stdc++.h>
using namespace std;

/*
hollow full pyramid-2 pattern

    *
   * *
  *   *
 *     *
*       *

*/

void pattern(int n)
{

    for (int i = 0; i < n; i++)
    {
        // for spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        cout << "*";

        // for spaces
        for (int j = 0; j < 2*i-1; j++)
        {
            cout << " ";
        }

       if(i!=0) 
        cout<<"*";

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