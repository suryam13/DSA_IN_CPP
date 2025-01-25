#include <bits/stdc++.h>
using namespace std;
/********* MUST REFER PROBELEM FOR PARENTHESIS LOGIC **********/

bool canBeValid(string s, string locked)
{
    // Approach 1
    //  //using stack
    //  stack<int> open;      // for storing only open
    //  stack<int> openClose; // for storing variable i.e. locked[i]==0

    // if (s.size() & 1)
    //     return false;

    // for (int i = 0; i < s.size(); i++) {
    //     if (locked[i] == '0')
    //         openClose.push(i);

    //     else if (s[i] == '(')
    //         open.push(i);

    //     else {
    //         if (!open.empty()) // means there are elements
    //             open.pop();

    //         else if (!openClose.empty())
    //             openClose.pop();

    //         else
    //             return false; // since there are no open available;
    //     }
    // }

    // while (!open.empty() && !openClose.empty() &&
    //        open.top() < openClose.top()) {
    //     open.pop();
    //     openClose.pop();
    // }

    // return open.empty(); // means there are elements in the openClose and they
    //               // can balance out each other as they are in even cnt

    // Approach-2 using simple 2 pass
    //  // In parenthesis always try stack it could be solved and keep in
    //  mind a
    //  // technique to traverse from right to left for close braces and left
    //  to
    //  // right for open braces;

    if (s.size() & 1)
        return false;
    // using L to R and R to L check
    int open = 0; // tracking open;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || locked[i] == '0') // always consider open
            open++;

        else
            open--;

        // means there are more close braces so cannot match
        if (open < 0)
            return false;
    }

    int close = 0; // tracking close;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ')' || locked[i] == '0') // always consider close
            close++;

        else
            close--;

        // means there are more open braces so cannot match
        if (close < 0)
            return false;
    }
    return true; // all good
}
int main()
{

    return 0;
}