#include <bits/stdc++.h>
using namespace std;
string postToInfix(string s)
{

    stack<string> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            // Building a String then pushing it
            string str;
            str.push_back(s[i]);
            st.push(str);
        }

        else // means an operator has come
        {
            //eg ab* we traverse from start as we want operand first --> 
            string s2 = st.top(); //b will come first 
            st.pop();
            string s1 = st.top();// then a and we want to make a * b
            st.pop();

            string modified = '(' + s1 + s[i] + s2 + ')';
            st.push(modified);
        }
    }

    return st.top();
}
int main()
{

    return 0;
}