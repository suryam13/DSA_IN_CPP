#include <bits/stdc++.h>
using namespace std;
string preToInfix(string pre_exp)
{

    // pre->inf  *ab we want operand to come first
    //*ab-->a*b so we have to go for operand first then have to start from back
    //a would be top1 and b would be top2 and we have to do  top1 operator top2 along with ()


    stack<string> st;

    for (int i = pre_exp.size() - 1; i >= 0; i--)
    {
        if (isalpha(pre_exp[i]))
        {
            string ans(1, pre_exp[i]); // makes string of len 1 char->string
            st.push(ans);
        }

        else
        {
            // means operator
            // we have to move from backwards
            // consider eg *ab->a*b
            string top1 = st.top(); // a
            st.pop();
            string top2 = st.top(); // b
            st.pop();

            string final = '(' + top1 + pre_exp[i] + top2 + ')';
            st.push(final);
            //--> (a*b)
        }
    }
    return st.top();
}
int main()
{

    return 0;
}