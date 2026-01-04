#include <bits/stdc++.h>
using namespace std;
// LC-647
//  T.C. O(N^2)
int expand(string s, int i, int j)
{
    int count = 0;

    while (i >= 0 && j < s.size() && s[i] == s[j])
    {
        count++;
        i--; // the motive is to start from inward and go outward
        j++;
    }
    return count;
}
int countSubstrings(string s)
{

    int total_count = 0;

    // either we can have odd length palindromic substring either we could
    // have even length palindromic substring

    // we will assume that there are two pointers placed in case of even
    // length substring it is one right after the other whereas in odd
    // length substring the pointers will be placed at one point only
    // considered as center and then would be expanded sequentially

    for (int center = 0; center < s.size(); center++)
    {
        int oddlen_substr = expand(s, center, center);
        // in case of odd length the pointers would be placed at one
        // location only and then would be expanded

        int evenlen_substr = expand(s, center, center + 1);

        total_count = total_count + oddlen_substr + evenlen_substr;
    }
    return total_count;
}
int main()
{

    return 0;
}