#include <bits/stdc++.h>
using namespace std;

//interesting problem
bool isPossibleDivide(vector<int> &nums, int k)
{

    // check if that many groups can be formed or not
    if (nums.size() % k != 0) // means not possible to form groups
        return false;

    map<int, int> mapy;

    for (auto it : nums)
    {
        mapy[it]++;
    } // storing the occurence of each number

    while (mapy.size()) // will loop unitll the elements in mapy is null
    {
        auto it = mapy.begin(); // points to begining element which is the
                                // smallest
        int val = (*it).first;  // it gives the key of the begining element

        for (int i = 0; i < k; i++)
        {
            if (mapy.find(val + i) != mapy.end())
            {
                mapy[val + i]--; // decrementing the count of that key

                // auto itt = mapy.find(val + i);
                // int check_val = (*itt).second;
                // above commented are other alternatives for mapy[val+i]
                // which is unuseful
                if (mapy[val + i] == 0)
                {
                    mapy.erase(val + i);
                }
            }

            else
                return false;
        }
    }

    return true;
}
int main()
{

    return 0;
}