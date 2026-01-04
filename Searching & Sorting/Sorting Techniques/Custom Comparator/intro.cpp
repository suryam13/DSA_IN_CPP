#include <bits/stdc++.h>
using namespace std;

//[] used for capturing what u want to use
auto comparator = [](int a, int b)
{
    if (a > b) // means ki yeh wali condition ko true karao jo pehla number aayega wo bada hoga
        return true;

    return false;
};

/*
In a C++ comparator for std::sort, no matter what logic you write inside, if it returns true for comp(a, b), it always means “put a before b”.
false means “put a after b (or equal)”.

so it means that if (a>b) return true;    -> it means that if there is something like 5>3 (a>b) then always put 'a' forward that is it would be sorted in descending order

when there is a case of equal values like eg- mapy[a] == mapy[b] so in such case always provide a more defined case beneath becuase when i write the condition as mapy[a] > mapy[b] true it means that if a has higher frequency than b then true means place a forward,else false means place b forward but what if both the frequency were equal so now in such a case we have something like ddll so at an instant d and l would be compared as the 1st pair so as we got false now the comparator has the authority to put that in any order but it would be towards lower frequency only lets say l first then d ->ld.Now in the second chance the second pair got compared so this time it thought d first then l so it became lddl but this is wrong as the sequence got distorted.
refer lc-451 for more clarity of the edge case

so we conclude that when we return false means the order is not guaranteed if two entities are found to have same distinguishing factor in general.
*/

int main()
{
    vector<int> v = {2, 3, 5, 6, 1};
    sort(v.begin(), v.end(), comparator);
    for (auto it : v)
    {
        cout << it;
    }
    return 0;
}