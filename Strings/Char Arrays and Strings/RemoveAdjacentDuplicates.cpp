#include <bits/stdc++.h>
using namespace std;
// L.C. 1047 babbar

// Approach-1 O(N^2) O(1)
/*
 string removeDuplicates(string s) {

        int i=0;
        int size=s.size();

        while(i<size-1)
        {
            if(s[i]==s[i+1])
            {
                s.erase(i,2);
                i=0;
            }
            else
            {
                i++;
            }
        }

        return s;

    }
*/

// Approach-2 O(N) O(N)
/*  string removeDuplicates(string s) {

        string str;

        for (int i = 0; i < s.size(); i++) {
            if (str.size() == 0 ||
                str.back() != s[i]) // checking the rightmost and current
                                    // element of extra and current respectively
            {
                str.push_back(s[i]);
            }

            else if (str.back() == s[i]) {
                str.pop_back();
            }
        }

        return str;
    }

*/

int main()
{

    return 0;
}