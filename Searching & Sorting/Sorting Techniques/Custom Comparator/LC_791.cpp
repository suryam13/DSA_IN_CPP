#include <bits/stdc++.h>
using namespace std;
string customSortString(string order, string s)
{
    auto compare = [order](char a, char b)
    {
        if (order.find(a) <
            order.find(
                b)) // means jiska iterator small hai usko pehle rakho means pehle chota wala iterator aayega if > means pehle bada wala iterator aayega
            return true;

        else
            return false;
    };
    sort(s.begin(), s.end(), compare);
    return s;
}
//whatever is true 
int main()
{

    return 0;
}