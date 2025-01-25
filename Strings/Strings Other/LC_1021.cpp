#include <bits/stdc++.h>
using namespace std;

//did it without stack took extra space O(N) and tc O(N) for traversing
string removeOuterParentheses(string s)
{

    string ans = "";
    int i = 0;
    int count = 0;
    bool check = true;
    int start = 0;

    while (i < s.size())
    {
        start = i;
        check = true;
        while (check && i < s.size())
        {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')')
                count--;
            if (count == 0)
            {
                check = false;
            }

            i++;
        }
        ans = ans + s.substr(start + 1, i - start - 2);
    }

    return ans;
}
int main()
{

    return 0;
}