#include <bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<vector<int>> &shifts)
{

    string ans = s;
    vector<int> tracker(s.size(), 0);
    // DIFFERENCE ARRAY TECHNIQUE-USED IN RANGE BASED MANIPULATION
    // QUESTIONS IT STATES THAT IN THE SPECIFIED RANGE WE HAVE TO ADD
    // THE VALUE AT THE START AND THEN SUBTRACT THE SAME VALUE JUST NEXT TO
    // THE END ELEMENT
    for (auto &shift : shifts)
    {

        if (shift[2] == 0) // backward
        {
            tracker[shift[0]] += -1;

            if (shift[1] + 1 < tracker.size())
                tracker[shift[1] + 1] -= -1;
        }

        else
        {

            tracker[shift[0]] += 1;

            if (shift[1] + 1 < tracker.size())
                tracker[shift[1] + 1] -= 1;
        }
    }

    // now calculating prefix sum
    for (int i = 1; i < tracker.size(); i++)
    {
        tracker[i] = tracker[i] + tracker[i - 1];
    }

    for (int i = 0; i < tracker.size(); i++)
    {

        // to drop the bigger value down
        int value = tracker[i] % 26;

        if (value <
            0) // so convert it into a cycle eg char is 'a' and val is -1 so
               // it should give 'z' so -1+26=25 then 'a' + 25 = 'z'
            value = value + 26;

        ans[i] = (((ans[i] - 'a') + value) % 26) +
                 'a'; // firstly dereferencing the alphabet number then
                      // adding the changes then rounding and then adding
                      // with 'a' to make char
    }

    return ans;
}
int main()
{

    return 0;
}