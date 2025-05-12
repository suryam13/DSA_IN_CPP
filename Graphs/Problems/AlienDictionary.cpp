#include <bits/stdc++.h>
using namespace std;

// GFG : Sheet
class Solution
{
public:
    string findOrder(vector<string> &words)
    {
        // we are revolving around the fact that which letter come sbefore which so topo sort is
        // the best choice

        // how many vertices ?
        // the unique letters prseent in the words

        vector<bool> presentChars(26, false);
        vector<int> inDegree(26, 0);
        unordered_map<char, vector<char>> adj;
        int cntChars = 0;

        // Mark present characters
        for (auto &word : words)
        {
            for (auto &ch : word)
            {
                presentChars[ch - 'a'] = true;
            }
        }

        // making adj list
        for (int i = 0; i < words.size() - 1; i++)
        {
            string str1 = words[i];
            string str2 = words[i + 1];

            // the eords lenght can mismatch so runninn through shorter length
            int len = min(str1.size(), str2.size());
            bool check = 1;

            for (int j = 0; j < len; j++)
            {
                if (str1[j] != str2[j])
                {
                    adj[str1[j]].push_back(str2[j]);
                    inDegree[str2[j] - 'a']++;
                    check = 0;
                    break;
                }
            }
            // check invalid case as the test acse suggests in further where code ot failed
            if (check && (str1.size() > str2.size()))
                return "";
        }

        string ans;
        queue<char> q;

        for (int i = 0; i < 26; i++)
        {
            // checking presentChar because there could be a case where there is no relation
            // of vertices but still the letter exists so consider that
            if (presentChars[i] && inDegree[i] == 0)
            {
                q.push('a' + i);
            }
        }

        while (!q.empty())
        {
            char ch = q.front();
            q.pop();

            ans.push_back(ch);

            for (auto &c : adj[ch])
            {
                inDegree[c - 'a']--;

                if (inDegree[c - 'a'] == 0)
                    q.push(c);
            }
        }

        // counting how many vertices are there in total becuase that can be predicted only through
        // presentChars and not adj
        for (int i = 0; i < 26; i++)
        {
            if (presentChars[i])
                cntChars++;
        }

        if (ans.size() < cntChars) // means all chars are not been visited by the queue so a cycle
            return "";

        return ans;
    }
};
int main()
{

    return 0;
}