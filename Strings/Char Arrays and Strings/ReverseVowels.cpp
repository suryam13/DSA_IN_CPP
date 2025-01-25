#include <bits/stdc++.h>
using namespace std;
// LC-345

bool isVowel(char c)
{
    char ch = tolower(c);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;

    return false;
}

string reverseVowels(string s)
{

    int start = 0;
    int end = s.size() - 1;

    while (start <= end)
    {
        if (isVowel(s[start]) && isVowel(s[end]))
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }

        else if (!isVowel(s[start]))
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