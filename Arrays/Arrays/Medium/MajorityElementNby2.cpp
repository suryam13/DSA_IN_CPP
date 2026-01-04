#include <bits/stdc++.h>
using namespace std;

// L.C-169

// to check which number comes more than N/2 times

/*
Bruteforce approach-iterate through 2 loops and count++ each to check which number comes n/2 times
T.C-O(N2 )
*/

/*
Better solution-hashmap
T.C. O(NlogN+N)
S.C-O(N)

 #include<bits/stdc++.h>
int majorityElement(vector<int> v) {

    map<int,int> mapy;

    for(int i=0;i<v.size();i++)
    {
        mapy[v[i]]++;
    }

    for(auto it:mapy)
    {
        if(it.second>(v.size()/2))
        return it.first;
    }
    return -1;
}
*/

/*
Optimised Approach
by moore's algorithm - it states that if the element is not cancelled out till the end of the array then it could be the majority element,if majority elment always exists in the array
T.C-O(N) if it is mentioned that majority element always exists
T.C.O(2N) if not then we would have to run the extra loop to verfiy if it is greater than n/2
else return -1

int majorityElement(vector<int>& nums) {

        int count = 0;
        int el = 0;

        //moore's algorithm
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                el = nums[i];
                count++;
            }

            else if (nums[i] == el)
                count++;

            else
                count--;
        }


        //this would be done only if the problem states that there might not be the majority element present in the array,so to verify we would do this
        // int cnt1 = 0;

        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == el)
        //         cnt1++;
        // }

        // if (cnt1 > (nums.size() / 2))
        //     return el;

        return -1;
    }
*/

int main()
{

    return 0;
}