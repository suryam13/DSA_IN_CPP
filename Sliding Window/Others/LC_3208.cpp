#include <bits/stdc++.h>
using namespace std;

/*
int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int i = 0;
        int j = 0;
        int n = colors.size();

        int cnt = 0;
        while (i < colors.size())
        {
            if (colors[j % n] != colors[(j + 1) % n]) // means alternate
                j++;

            //moving j as per the count only because when subtracted with i needs to be a proper number
            //with respect to distance doing % n to assure that it fits as per the index according to count

            else { //not alternate so just start i from that jth + 1 index only as if not alternate means it
                   //wont be alternate throughout that window so just skip that
                i = j + 1;
                j = (j + 1) % colors.size();
            }

            if (j - i + 1 == k) // means length reached
            {
                cnt++;
                i++;  //now check for next window
            }
        }

        return cnt;
    }
*/
int main()
{

    return 0;
}