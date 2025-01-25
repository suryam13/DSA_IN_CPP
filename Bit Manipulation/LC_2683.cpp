#include<bits/stdc++.h>
using namespace std;
 bool doesValidArrayExist(vector<int>& derived) {

        if (derived.size() == 1 && derived[0] == 1)
            return false; // as it is not possible to put in different element
                          // at a single position
                          
        else if (derived.size() == 1 && derived[0] == 0) // possible as put 0 in and it would be same
            return true;

        vector<int> dummy;

        if (derived[0] == 0) // means it has to be same
        {
            dummy.push_back(0);
            dummy.push_back(0);
        }

        else {
            dummy.push_back(1);
            dummy.push_back(0);
        }

        int i = 1;
        while (i < derived.size()) {
            if (i == derived.size() - 1) {
                if (dummy.back() ^ dummy.front() != derived.back())
                    return false;

                return true;
            }

            if (derived[i] == 0) // means same as previous
            {
                dummy.push_back(dummy.back());
            }

            else // opposite
            {
                int j = 0;
                if (dummy.back() == j)
                    j = 1;

                dummy.push_back(j);
            }

            i++;
        }
        return true;
    }
 int main()
{
    
    return 0;
}