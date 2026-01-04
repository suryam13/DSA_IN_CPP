#include <bits/stdc++.h>
using namespace std;
// SHEET : LC - 155
vector<pair<int, int>> store;
/*
Another method to do in N space is take min

if curr<min //means min has to be updated
min=val

to push-> 2*curr-previous min
v.push_back()


while popping if min>curr
mini=2*mini-curr

and pop
*/
// MinStack() {}

void push(int val)
{

    if (store.empty())
        store.push_back(make_pair(val, val));

    else
    {
        if (store.back().second < val) // means back one is the minimum
            store.push_back(make_pair(val, store.back().second));

        else // current is minimum
            store.push_back(make_pair(val, val));
    }
}

void pop() { store.pop_back(); }

int top() { return store.back().first; }

int getMin()
{
    if (store.empty())
        return -1;

    return store.back().second;
}
int main()
{

    return 0;
}