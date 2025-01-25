#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 0 || n == 1)
        return false;

    int count = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;
            if ((n / i) != i)
                count++;
        }
    }

    if (count == 2)
        return true;

    else
        return false;
}
int main()
{
    int n;
    cout << "enter any number which u want to check : " << endl;
    cin >> n;

    if (isPrime(n))
        cout << "prime";

    else
        cout << "not prime";

    return 0;
}