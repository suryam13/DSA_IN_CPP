#include <bits/stdc++.h>
using namespace std;

/*
brute is to pick up each element and check whether it appears floor of N/3 times or not which will end up taking O(N2)

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) { //doing ls[0]!=v[i] because if again 1 comes then again it will count majority and push back 1 which is not required,and at max there can be three majority elements either 0 1 or 2 so for 0 we have specified the condition to check if size is 0 and for 2 it will automatically take and end the break the loop 
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
}
*/

/*
better-O(NlogN)
S.C. O(N)

vector<int> majorityElement(vector<int> nums) {
     vector<int> vv;

        int majority=floor((double)nums.size()/(double) 3);

        map<int,int> mapy;

        for(auto it:nums)
        {
            mapy[it]++;
            if(mapy[it]==majority+1)
            vv.push_back(it);
        }

        // for(auto itt:mapy)
        // {
        //     if(itt.second>majority)
        //     v.push_back(itt.first);
        // }

        sort(vv.begin(),vv.end());
        return vv;
}
*/

/*
optimised-through moore's voting algorithm for n/3 majority

   vector<int> majorityElement(vector<int>& nums) {

        //by moore's voting algorithm
        int count1=0;
        int count2=0;
        int el1=0;
        int el2=0;


        for(int i=0;i<nums.size();i++)
        {
            if(count1==0 && el2!=nums[i]) //extra condition because both of the elemnts should not be the same
            {
                count1=1;
                el1=nums[i];
            }

            else if(count2==0  && el1!=nums[i])
            {
                count2=1;
                el2=nums[i];
            }

            else if(el1==nums[i] )
            {
                count1++;
            }

            else if(el2==nums[i])
            {
                count2++;
            }

            else
            {
                count1--;
                count2--;
            }
        }


        count1=0;
        count2=0;
         //verifying coz there are three case either 0 1 2 at max 2 elements are possible which can have a majority n/3
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==el1)
            count1++;

            else if(nums[i]==el2)
            count2++;
        }



        vector<int> v;
        if(count1> floor((double)nums.size()/(double)3))
        v.push_back(el1);

        if(count2> floor((double)nums.size()/(double)3))
        v.push_back(el2);

        return v;

    }
*/
int main()
{

    return 0;
}