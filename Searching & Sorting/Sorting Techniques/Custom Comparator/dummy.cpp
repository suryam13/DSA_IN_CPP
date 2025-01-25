#include <bits/stdc++.h>
using namespace std;

//[] used for capturing what u want to use 
auto comparator = [](int a, int b)
{
    if (a > b) // means pehle wala number jo answer aayega woh bada hona chahiye
        return true;

    return false;

    // return (a>b);
};

/*
simply remember that if > matlab pehle bada aana chahiye
 */

int main()
{
    vector<int> v = {2, 3, 5, 6, 1};
    sort(v.begin(), v.end(), comparator);
    for (auto it : v)
    {
        cout << it;
    }
    return 0;
}