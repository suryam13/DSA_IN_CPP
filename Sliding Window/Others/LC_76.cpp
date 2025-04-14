#include <bits/stdc++.h>
using namespace std;
bool check(unordered_map<char, int> &freqT, unordered_map<char, int> &freqS)
{
    for (auto &[key, value] : freqT)
    {
        if (freqT[key] > freqS[key]) // means it hasn't been equal
            return false;
    }
    return true; // alright;
}

string minWindow(string s, string t)
{

    unordered_map<char, int> freqT; // reference
    unordered_map<char, int> freqS; // actual

    for (auto &el : t)
        freqT[el]++;

    int i = 0;
    int j = 0;

    int start = -1;
    int end = -1;
    int minLen = INT_MAX;
    int size = s.size();

    while (j < size)
    {
        freqS[s[j]]++;

        if (check(freqT, freqS))
        {
            if ((j - i + 1) < minLen)
            {
                // change
                minLen = j - i + 1;
                start = i;
                end = j;
            }

            // now we would decrement
            while (true)
            {
                freqS[s[i]]--;
                i++;

                if (check(freqT, freqS))
                {
                    if ((j - i + 1) < minLen)
                    {
                        // change
                        minLen = j - i + 1;
                        start = i;
                        end = j;
                    }
                }

                else
                    break;
            }
        }

        j++;
    }

    if (start == -1 && end == -1)
        return "";

    return s.substr(start, end - start + 1);
}
int main()
{

    return 0;
}