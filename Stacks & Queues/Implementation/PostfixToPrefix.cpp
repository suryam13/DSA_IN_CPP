#include <bits/stdc++.h>
using namespace std;
string postToPre(string post_exp)
{

    // ab* --> *ab
    // means have to go for operand first
    // so 'b' would be top1 'a' would be top2
    // and we have to do operator top2 top1

    stack<string> st;

    for (int i = 0; i < post_exp.size(); i++)
    {
        if (isalpha(post_exp[i]))
        {
            string ans(1, post_exp[i]);
            st.push(ans);
        }

        else // means it is an operator
        {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            string ans = post_exp[i] + top2 + top1;
            st.push(ans);
        }
    }
    return st.top();
}
int main()
{

    return 0;
}