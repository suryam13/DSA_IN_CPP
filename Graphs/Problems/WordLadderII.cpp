#include <bits/stdc++.h>
using namespace std;

// SHEET : GFG
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
{

    // over here i have to store multiple strings in a container so as to get the sequence

    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<vector<string>> ans;
    queue<vector<string>> q;
    bool check = false;
    q.push({beginWord});

    while (!q.empty())
    {
        int size = q.size();

        vector<string> toRemove;

        if (check)
            break;

        while (size--)
        {
            auto topy = q.front();
            string s = topy.back(); // the string on to which the iteration needs to be done

            if (s == endWord) // means we have found the shortest path transformation so this is going to be the last level
            {
                ans.push_back(topy);
                check = 1;
            }

            q.pop();

            for (int i = 0; i < beginWord.size(); i++)
            {
                // onto each idx check the possibility
                string dummy = s; // to apply the dummy changes
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    dummy[i] = ch;
                    if (st.count(dummy)) // means this is a part of sequence
                    {
                        toRemove.push_back(dummy);
                        // we will remove at the end of the entire inner size loop
                        // becuase the same word can be use in the current by others
                        topy.push_back(dummy);
                        q.push(topy);
                        topy.pop_back();
                        // doing this because we have to add other words also as a sequence
                        // so going back to the original ladder
                    }
                }
            }
        }

        // now please remove the exhausted string as they may be redundant in further levels
        for (auto &s : toRemove)
        {
            st.erase(s);
        }
    }

    return ans;
}
int main()
{

    return 0;
}