#include <bits/stdc++.h>
using namespace std;

///SHEET : InteviewBit
vector<int> prevSmaller(vector<int> &A)
{

    vector<int> ans;
    stack<int> st;

    for (auto &el : A)
    {
        while (!st.empty() && st.top() >= el) // as we want the smaller then the curr
        {
            st.pop();
        }

        if (st.empty())
            ans.push_back(-1);

        else
            ans.push_back(st.top());

        st.push(el);
    }
    return ans;
}

int main()
{

    return 0;
}