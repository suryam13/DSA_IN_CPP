#include <bits/stdc++.h>
using namespace std;
int countPalindromicSubsequence(string s)
{

    // The trick is that in 3 length subsequenece first and last is same
    // so find out the first and last occurence of letter

    int cnt = 0;
    unordered_set<char> letters(s.begin(), s.end());
    // this consists of unique letters present in the string

    for (auto letter : letters) // iterating over each letter in set
    {
        int f_idx = -1;
        int l_idx = -1;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == letter && f_idx == -1)
                f_idx = i;

            if (s[i] == letter)
                l_idx = i;
        }

        // now determing how many unique chars are there in between ranges
        unordered_set<char> unique;
        for (int i = f_idx + 1; i < l_idx; i++)
        {
            unique.insert(s[i]);
        }

        cnt += unique.size();
    }
    return cnt;
}
int main()
{

    return 0;
}