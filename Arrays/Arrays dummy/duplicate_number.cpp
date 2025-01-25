#include<bits/stdc++.h>
using namespace std;

//one number is repeated

//sort and compare whether i==i+1

//mark index as -ve

//get the element at the original position

int findDuplicate(vector<int>& nums) {

        // sort(nums.begin(),nums.end());

        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]==nums[i+1])
        //     return nums[i];
        // }
        // return -1;

        int i = 0;

        while (nums[i] != nums[nums[i]])
            swap(nums[i], nums[nums[i]]);

        return nums[i];
    }


 int main()
{
    
    return 0;
}