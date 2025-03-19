#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int>& nums,int k,int mid)
{
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<=mid) //means it can be there as the condition is true and the possibility of nums lies
        {
           i++; //doing it twice as to skip the next idx
           k--;
        }
        /*
        In this conditioal we are checking whether it is possible to get the minimum barrier not exactly 
        that value mid suppose in a test case 4 comes but that value is not there inside the nums then 
        as the condition follows it would give true as it is possible to get that amount of elements less than
        4.After that in the next iteration the value 3 would be checked and it would be there inside the nums 
        and it would still follow the condition so eventually our answer would be right.
        */
    }

    if(k<=0) return true; //at least k is said means it can be greater than k too

    return false;
}


int minCapability(vector<int>& nums, int k) {
//T.C. O(max(nums)*N) //as in the function we are traversing N in worst case and max(nums) for search space
    int left=*min_element(nums.begin(),nums.end());
    int right=*max_element(nums.begin(),nums.end());
    int mid;
    int ans; //it is told that ans always exists so it wont be -1


    while(left<=right)
    {
        mid=left+(right-left)/2;

        if(possible(nums,k,mid))
        {
            //store the possible ans and go to left
            ans=mid;
            right=mid-1;
        }

        else
        {   
            //go right as that is not possible
            left=mid+1;
        }

    }

    return ans;  
    
    //Interesting and a bit tricky problem on BS on Answers

    /*
    Whenever the problem demands minimum of maximum or maximum of minimum it is sure shot a problem of Binary
    Search.

    We have to find the maximum capability first, means we if that capability is possible then go left
    but before that store as it could be the minimum, then go to left,else not possible then go right to find 
    the possibility of capability exists or not.

    Now how would we get the search space ?
    We are told to get the minimum of maximum capabilities means that capability would definitely exist in the
    nums array so either it could eb minimum in the array or the maximum value it would be ranging between 
    them only.
    */

}
 int main()
{
    
    return 0;
}