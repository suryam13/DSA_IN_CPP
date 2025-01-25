#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal)
{
    // // left rotate by using reverse
    // int i = 1;
    // string k = s;

    // while (i <= s.size()) {

    //     reverse(s.begin() + i, s.end());
    //     reverse(s.begin(), s.begin() + i);
    //     reverse(s.begin(), s.end());

    //     if (s == goal)
    //         return true;

    //     s = k;
    //     i++;
    // }
    // return false;

    // //right rotate by using reverse
    // int size = s.size();
    // int len = s.size();

    // while (size--) {
    //     // right shifting by 1 and checking again and again
    //     reverse(s.begin(), s.end() - 1);         // first are shifted
    //     reverse(s.begin() + (len - 1), s.end()); // last 1
    //     reverse(s.begin(), s.end());

    //     if (s == goal)
    //         return true;
    // }
    // return false;

    // using rotate function the times of its length

    // int len = s.size();

    // if (s.size() != goal.size())
    //     return false;

    // while (len--) {
    //     rotate(s.begin(), s.begin() + 1, s.end());

    //     if (s == goal)
    //         return true;
    // }
    // return false;

    // using concatentatiom
    // if a particular string is concatenated with itself then it contains
    // all the shifted values as substring in it
    if (s.size() != goal.size())
        return false;

    string dummy = s + s;

    if (dummy.find(goal) == string::npos)
        return false;

    return true;
}

int main()
{

    return 0;
}