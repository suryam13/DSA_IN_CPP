#include <bits/stdc++.h>
using namespace std;
// SHEET : LC-20
bool isValid(string s)
{
    stack<char> st;

    for (auto it : s)
    {

        if (it == '(' || it == '{' || it == '[')
            st.push(it);

        else
        {

            if ((st.top() == '(' && it == ')') ||
                (st.top() == '{' && it == '}') ||
                (st.top() == '[' && it == ']'))
                st.pop();

            else
                return false;
        }
    }
    return st.empty();
}
int main()
{

    return 0;
}