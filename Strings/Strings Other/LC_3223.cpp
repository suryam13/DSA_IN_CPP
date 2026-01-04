#include <bits/stdc++.h>
using namespace std;
int minimumLength(string s)
{

    // APPPROACH-1
    unordered_map<char, int> mapy; // 26 lowercase letters so O(26) constant space
    for (auto &ch : s)
        mapy[ch]++;

    int len = 0;
    for (auto &val : mapy)
    {
        if (val.second % 2) // means odd occurences so there will be at least   1 char
                            // left after manipulations  eg: a a a a a --> a
            len++;

        else // even length so two occurences would be left after
             // manipulationss eg: a a a a --> a a
            len += 2;
    }
    return len;

    // // APPPROACH-2
    // unordered_map<char, int> mapy; // 26 lowercase letters so O(26)
    // constamt space

    // int len = 0;//here we are storing the length of deleted chars
    // for (auto& ch : s) {

    //     mapy[ch]++;
    //     if (mapy[ch] == 3) { //--> a a a so here deleted would be 2 and 1
    //     'a' left so the count changes to 1 occurence in the map
    //         len = len + 2;
    //         mapy[ch] = 1;
    //     }
    // }
    // return s.size() - len;//original-deleted = leftover
}
int main()
{

    return 0;
}