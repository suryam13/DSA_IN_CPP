#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "enter the numbers of time you want to feed digits" << endl;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int digit;
        cout << "enter the " << i + 1 << " digit : " << endl;
        cin >> digit;

        if (i > 0 && i < n && digit < 0)
        {
            cout << "falsy input" << endl;
            break;
        }

        if (ans < 0)
            digit = (-digit);

        ans = (ans * 10) + digit;
        cout << ans << endl;
    }
    cout << "your number of iterations of creating digit is over :) the final digit obtained is " << ans;

    return 0;
}