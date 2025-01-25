#include <bits/stdc++.h>
using namespace std;
// LC-2325
// T.C O(NLogN)
string decodeMessage(string key, string message)
{

    map<char, char> mapy;
    char alpha = 'a';

    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] == ' ')
            continue;

        else
        {
            if (mapy.find(key[i]) == mapy.end())
            {
                mapy[key[i]] = alpha; // over here when i write ans[it],yes it means ans['character'] but its typecasted to int hence we have taken the char array size of more than 256
                alpha++;
            }
        }
    }

    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] == ' ')
            continue;

        else
            message[i] = mapy[message[i]];
    }

    return message;
}

string decodeMessage(string key, string message)
{

    // without hashmap,doing only using char array

    // creating mapping
    char ans[300] = {0};
    char alpha = 'a';

    for (auto it : key)
    // auto refers to directly accessing the char element insteead of the index
    {
        if (it == ' ')
            continue;

        if (ans[it] == 0)
        {
            ans[it] = alpha;
            alpha++;
        }
    }

    // using mapping
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] == ' ')
            continue;

        message[i] = ans[message[i]];
    }

    return message;
}
int main()
{
    return 0;
}