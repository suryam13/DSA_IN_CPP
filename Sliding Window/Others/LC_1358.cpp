#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s)
{
    // a b c
    vector<int> chary(3, 0);

    int i = 0;
    int j = -1; // doing this to write the while loop in such a condition that it stops when all the map values
    // are greater than 1
    int cnt = 0;
    int size = s.size();

    while (j < size)
    {
        while (chary[0] <= 0 || chary[1] <= 0 || chary[2] <= 0) // untill all have some values continue
        {
            j++;
            // move j ahead
            // started it from -1 so it would stop immediately at the index where the requirements are
            // fulfilled

            if (j == s.size())
                break; // out of bound

            chary[s[j] - 'a']++;
        }

        cnt++;
        cnt += s.size() - j - 1; // till end entire would be a valid one so count from end to current

        chary[s[i] - 'a']--;
        i++; // shrink and check for the next count of subarrays
    }
    return cnt;
}
int main()
{

    return 0;
}