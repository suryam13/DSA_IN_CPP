#include <bits/stdc++.h>
using namespace std;
// LC : 2698
vector<string> v;
bool check(string square, string str, int i, int value)
{

    if (i == square.size())
    {

        int sum = 0;
        for (auto it : v)
        {
            int comp = stoi(it);
            sum += comp;
        }

        if (sum == value)
            return true;

        return false;
    }

    for (int j = i; j < square.size(); j++)
    {
        str.push_back(square[j]);
        v.push_back(str);

        if (check(square, "", j + 1, value))
            return true;

        v.pop_back();
    }

    return false;
}
int punishmentNumber(int n)
{

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        int num = i * i; // the value obtained  after squaring

        if (check(to_string(num), "", 0, i))
            sum += num;

        v.clear();
    }

    return sum;
}
int main()
{

    return 0;
}