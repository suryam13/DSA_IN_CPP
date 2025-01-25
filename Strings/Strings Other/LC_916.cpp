#include <bits/stdc++.h>
using namespace std;
vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{

    /*** OPTIMISED APPROACH ***/
    vector<string> ans;

    vector<int> main(26, 0);

    for (auto it : words2)
    {
        vector<int> dummy(26, 0);
        for (auto chars : it)
            dummy[chars - 'a']++;

        for (int i = 0; i < 26;
             i++)
        { // only update if u find that there are more than that
          // amt of letters in a specific string
            if (dummy[i] > main[i])
                main[i] = dummy[i];
        }
    }

    for (auto it : main)
    {
        if (it > 0)
            cout << it;
    }

    for (auto &word1 : words1)
    {
        vector<int> temp(main); // a temp so the main vector isn't tampered
        for (auto it : word1)
        {
            temp[it - 'a']--;
        }

        int i;
        for (i = 0; i < 26; i++)
            if (temp[i] > 0) // means there is some letter missing to be
                             // there in the main word to be valid
                break;

        if (i >= 26) // means we traversed entire but didnt found any char
                     // that needs to be there in the main string so the
                     // main string is valid
            ans.push_back(word1);
    }

    return ans;

    //     /*** TLE APPROACH ***/
    //     for (auto& word1 : words1) {

    //         int cnt1 = 0;
    //         for (auto& word2 : words2) {
    //             string dummy = word1;
    //             int cnt = 0;
    //             for (auto chars : word2) {
    //                 int ind = dummy.find(chars);
    //                 if (ind != string::npos) {
    //                     dummy[ind] = '-';
    //                     cnt++;
    //                 }

    //                 else
    //                     break;
    //             }
    //             if (cnt == word2.size())
    //                 cnt1++;
    //         }
    //         if (cnt1 == words2.size())
    //             ans.push_back(word1);
    //     }

    //     return ans;
}
int main()
{

    return 0;
}