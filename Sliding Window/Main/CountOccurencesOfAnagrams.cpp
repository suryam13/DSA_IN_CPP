#include <bits/stdc++.h>
using namespace std;
/*
Through this i lerant about the template where i keeps moving till the end  whereas j moves in certain conditions
*/
//GFG
bool check(vector<int> &v)
{
    for (auto it : v)
    {
        if (it > 0)
            return false;
    }
    return true;
}

int search(string pat, string txt)
{

    int n = txt.size();
    int k = pat.size();
    int cnt = 0;

    vector<int> v(26, 0);
    for (char &it : pat)
    {
        v[it - 'a']++;
    } // this will increase the count of alphabets in pat

    int i = 0;
    int j = 0;

    while (i < n)
    {
        v[txt[i] - 'a']--; // decreasing the count as it is visisted

        if (i - j + 1 == k) // means we have reached the window
        {
            if (check(v))
                cnt++; // means all are 0 so goal achieved

            // now increasing j
            v[txt[j] - 'a']++; // making it again back normal by each step
            j++;
        }

        i++;
    }
    return cnt;
}
int main()
{

    return 0;
}