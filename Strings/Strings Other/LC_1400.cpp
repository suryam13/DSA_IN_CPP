#include <bits/stdc++.h>
using namespace std;
bool canConstruct(string s, int k)
{

    vector<int> freq(26, 0);
    // This problem is oall about observation and dry run refer MIK'S video

    if (k == s.length())
        return true; // since individual chars can be considered to be
                     // paindrome
    if (k > s.length())
        return false; // not possible to make

    for (auto &ch : s)
    {
        freq[ch - 'a']++;
    }

    // we dont have probelm with even cnt as they can adjust and make
    // themselves palindrome
    int odd_count = 0;
    for (auto &it : freq)
    {
        if (it & 1)
            odd_count++;
    }

    return odd_count <= k; // if odd chars are more means there is no space to enter into
                           // another palindrome,returns false if odd_count is less
}
int main()
{

    return 0;
}