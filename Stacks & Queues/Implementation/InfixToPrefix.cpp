#include <bits/stdc++.h>
using namespace std;
// this is the key change while(!st.empty() && priority(s[i])<priority(st.top()))
int priority(char ch)
{
    if (ch == '^')
        return 3;

    else if (ch == '*' || ch == '/')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;

    else
        return 0;
}
// Function to convert an infix expression to a postfix expression.
string convert(string &s)
{

    // reverse(s.begin(),s.end());
    // also convert the braces '('->')' and vice verca

    string ans;
    stack<int> st;

    // giving precedence values

    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]) || isdigit(s[i])) // simply build ans as this is operand
            ans.push_back(s[i]);

        else if (s[i] == '(') // push into the stack
            st.push(s[i]);

        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }

        else // means it is an operator
        {
            if (s[i] == '^') // so if multiple ^ are there then please pop it out the tos and then push curr
            {
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            // if the precedence of curr is lower than top of stack then pop tos and if same then dont do anything as that is the case in this conversion
            while (!st.empty() && priority(s[i]) < priority(st.top()))
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}