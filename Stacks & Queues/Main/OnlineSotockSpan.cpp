#include <bits/stdc++.h>
using namespace std;
// SHEET : LC-901

stack<pair<int, int>> st; // value //delCountIncluding the Current

int next(int price)
{

    int cnt = 1; // as the minimum stock span is 1
    while (!st.empty() && st.top().first <= price)
    {

        cnt = cnt + st.top().second;
        st.pop();
    }

    st.push(make_pair(price, cnt));

    return cnt;
}
int main()
{

    return 0;
}