#include <bits/stdc++.h>
using namespace std;
int minChanges(string s)
{
    int changes = 0;
    int cnt = 1;
    char curr = s[0];

    for (int i = 1; i < s.size(); i++)
    {
        if ((s[i] != curr) &&
            ((cnt & 1) == 1)) // means before this length was odd and pattern is been
                              // breaked so need to change to make it even
        {
            changes++;
            cnt = 0;
        }

        else if (s[i] != curr && (cnt & 1) == 0)
        { // prev was of even length so start new substr no need to make changes break that earlier one into valid one
            curr = s[i];
            cnt = 1;
        }

        else if (cnt == 0)
        {
            curr = s[i]; // means new sequence is to be started
            cnt++;
        }

        else if (s[i] == curr) // if equal then simply proceed
            cnt++;
    }
    return changes;

    // METHOD 2
    // we know that we just have to send the minimum changes so lets take minimum even length
    int changes = 0;

    for (int i = 0; i < s.length(); i = i + 2)
    {
        if (s[i] != s[i + 1])
            changes++;
    }
    return changes;
}
int main()
{

    return 0;
}