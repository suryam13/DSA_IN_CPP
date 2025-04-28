#include <bits/stdc++.h>
using namespace std;

// count and say
void helper(string &start, string &ans, int cnt)
{
    if (cnt == 1)
        return;

    ans.clear();

    int i;
    int chary = 0;
    for (i = 0; i < start.size(); i++)
    {
        if (i > 0 && start[i - 1] != start[i]) // then frame
        {
            char ch = start[i - 1];
            string freqy = to_string(chary);

            ans += freqy;
            ans += ch;
            chary = 0;
        }

        chary++;
    }
    // the last would be remaining so add that too
    char ch = start[i - 1];
    string freqy = to_string(chary);
    ans += freqy;
    ans += ch;

    start = ans;

    helper(start, ans, cnt - 1);
}
string countAndSay(int n)
{

    string start = "1";
    string ans = "1";
    helper(start, ans, n);
    return ans;
}
int main()
{

    return 0;
}