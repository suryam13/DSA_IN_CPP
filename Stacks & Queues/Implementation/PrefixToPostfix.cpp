#include <bits/stdc++.h>
using namespace std;
string preToPost(string pre_exp)
{

    // *ab--> ab*
    // means we have to go from backside resulting in top1 top2 operator

    stack<string> st;
    for (int i = pre_exp.size() - 1; i >= 0; i--)
    {
        if (isalpha(pre_exp[i]))
        {
            string dummy(1, pre_exp[i]);
            st.push(dummy);
        }

        else // means operator has arrived
        {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            string ans = top1 + top2 + pre_exp[i];
            st.push(ans);
        }
    }
    return st.top();
}
int main()
{

    return 0;
}