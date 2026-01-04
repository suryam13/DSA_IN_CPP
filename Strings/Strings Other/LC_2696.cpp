#include <bits/stdc++.h>
using namespace std;
int minLength(string s)
{

    int len = s.size();
    int i = 0;
    int j = 1;

    while (j < len)
    {
        // to handle if i goes onto negative
        if (i < 0)
        {
            i++;
            s[i] = s[j];
        }

        else if ((s[i] == 'A' && s[j] == 'B') ||
                 (s[i] == 'C' && s[j] == 'D'))
        {
            i--;
        }

        else // no worries
        {
            i++;
            s[i] = s[j];
        }
        j++;
    }
    return i + 1;
}
int main()
{

    return 0;
}