#include<bits/stdc++.h>
using namespace std;
int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

            //if nums2 is even means the pairings with num1 would result into nums1 element being even times so they would be removed automatically

            int m=nums1.size();
            int n=nums2.size();

            int xor1=0;
            int xor2=0;

            for(auto &nums:nums1) xor1^=nums;

            for(auto &nums:nums2) xor2^=nums;

            if( !(m&1) && !(n&1)) //means both are even 
            return 0;

            else if( !(m&1) && n&1) //means m is even and n is odd so as nums2 would be paired with each element in nums1 so it would be 0.
            return xor1;

            else if(m&1 && !(n&1)) //means m is odd and n is even 
            return xor2;

            else //both are odd
            return xor1^xor2;

            
    }
 int main()
{
    
    return 0;
}