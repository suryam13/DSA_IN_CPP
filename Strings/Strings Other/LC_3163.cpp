#include <bits/stdc++.h>
using namespace std;
string compressedString(string word)
{

    int cnt = 1;
    string ans = "";

    for (int i = 0; i < word.size(); i++)
    {
        if (i == word.size() - 1)
        {
            if (i == 0)
                ans.append(to_string(cnt) + word[i]);
            else
                ans.append(to_string(cnt) + word[i]);
        }

        else if (word[i] == word[i + 1] && cnt < 9)
            cnt++;

        else
        {
            ans.append(to_string(cnt) + word[i]);
            cnt = 1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}