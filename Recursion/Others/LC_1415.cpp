#include <bits/stdc++.h>
using namespace std;
vector<string> ans;

/*
    T.C At each place we 2 possibilities as the current should not be same as the previous only at 1st position we 3
    possibilities so it boils down to 2^n * n(for pushing the string into ans) time

    S.C. same as tc as the answer would be storing n elements of 2^n length
    Stack space : O(n) upto the length of to be made string

    A bit optimization could be done as to take a count var and only push when that is equal to the kth index string
*/

void helper(string &s, string &temp, int n)
{
    if (temp.size() == n)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (!temp.empty() && temp.back() == s[i])
            continue; // make sure the previous should not be same as the to be added one

        temp.push_back(s[i]);
        helper(s, temp, n);
        temp.pop_back(); // pop and try further possible
    }
}

string getHappyString(int n, int k)
{
    // here we are trying out combinations
    string s = "abc";
    string temp = "";
    helper(s, temp, n);

    if (k > ans.size())
        return "";

    return ans[k - 1];
}
int main()
{

    return 0;
}