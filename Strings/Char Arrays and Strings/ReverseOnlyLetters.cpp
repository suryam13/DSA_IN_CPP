#include <bits/stdc++.h>
using namespace std;
// LC-917

string reverseOnlyLetters(string s)
{

    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        if (!((s[start] >= 65 && s[start] <= 90) ||
              (s[start] >= 97 && s[start] <= 122)))
            start++;

        else if (!((s[end] >= 65 && s[end] <= 90) ||
                   (s[end] >= 97 && s[end] <= 122)))
            end--;

        else
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    return s;
}

string reverseOnlyLetters(string s)
{

    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        if (isalpha(s[start]) && isalpha(s[end]))
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }

        else if (!isalpha(s[start]))
            start++;

        else
            end--;
    }

    return s;
}
int main()
{

    return 0;
}