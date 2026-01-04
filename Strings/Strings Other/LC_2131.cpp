#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {

        /*
        Conditions:
        1.if different char in string then check whetehr reverse exists and cnt+=2 as we got two strings
         valid
        2.if same char in string just increase the cnt of that,we will check later which has maximum odd
         frequecy and that would be considered as odd elements can be placed inn the exact middle of the
         palindromic string and they would be palindromic
        3.Now the ones which are odd and not max (for same letters),we will take the even cnt that can
        be placed with out any hesitation at a fraction n/2 at the ends
        */

        unordered_map<string, int> mapy;
        int cnt = 0;
        int maxi = INT_MIN;

        for (auto &word : words)
        {
            if (word[0] == word[1]) // as it as an example of same letters 'gg'
                mapy[word]++;

            else
            {
                string check;
                check.push_back(word[1]);
                check.push_back(word[0]);

                if (mapy[check] > 0)
                {
                    // we founs a pair of palindrome words
                    cnt += 2;
                    mapy[check]--;
                }

                else
                {
                    mapy[word]++;
                }
            }
        }

        int temp = 0;
        bool check = false;
        // now checking which same letter element has the max odd frequency,in case of even consider all
        // // for (auto &[key, value] : mapy)
        // {
        //     if (key[0] == key[1])
        //     {
        //         if (value & 1)
        //         {
        //             check = true;
        //             temp += value - 1; // just consider the even frequency of odd times occuring same chars
        //             // dont worry the frequency of maxi we will consider it in last
        //         }

        //         else
        //         {
        //             cnt += value;
        //         }
        //     }
        // }

        if (check) // means we have some odd occuring frequency
        {
            // now the temp would be consisting of all the even frequency of odd occuring elments so
            // now the max appearing one would be just + 1 so add that'
            cnt += temp + 1; // as it
        }

        return 2 * cnt;
    }
};
int main()
{

    return 0;
}