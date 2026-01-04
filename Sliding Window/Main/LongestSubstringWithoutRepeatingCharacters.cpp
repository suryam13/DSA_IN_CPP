#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {

        // Using sliding window

        int i = 0;
        int j = 0;
        int maxLen = 0;
        vector<int> mapy(256, -1);
        // unordered_map<char, int> mapy;
        // if using this then in place of mapy[s[j]]==-1 write mapy.find()

        while (j < s.size()) {
            if ((mapy[s[j]] == -1) ||
                mapy[s[j]] < i) // valid because if it is less than i then no
                                // need to worry as it is not inside the window
            {
                maxLen = max(maxLen, j - i + 1);

                mapy[s[j]] = j; // configuring it since it has been found now

                j++;
            }

            else // means it has been repeated
            {
                i = mapy[s[j]] + 1; // moving i before the repeated guy to
                                    // ensure that the window is valid
                mapy[s[j]] = j;     // now tracking it at new index
                j++;
            }
        }

        return maxLen;
    }
 int main()
{
    
    return 0;
}