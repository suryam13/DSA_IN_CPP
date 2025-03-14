#include<bits/stdc++.h>
using namespace std;
//DIFEFRECE ARRAY TECHNIQUE
bool diffArrTech(vector<int>& nums, vector<vector<int>>& queries,int mid)
{
    vector<int> prefix(nums.size(),0);

    for(int i=0;i<=mid;i++) //traversing queries uptill mid
    {
       int start = queries[i][0];
       int end = queries[i][1];
       int value = queries[i][2];

       prefix[start]-=value;
       if(end+1<nums.size())
       prefix[end+1]+=value;

    }

    //calculating prefix sum

    for(int i=1;i<nums.size();i++)
    {
        prefix[i]=prefix[i]+prefix[i-1];

    }

    for(int i=0;i<nums.size();i++)
    {
        if(prefix[i]+nums[i]>0)
        return false;
    }

    return true;



}
int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

    //using difference array technique + binary search 

    //if all are 0 in nums then return 0,using all_of function of STL
    auto lambda=[](int x){
        return x==0; //true if x==0
    };

    if(all_of(nums.begin(),nums.end(),lambda))
    return 0;

    int l=0;
    int r=queries.size()-1;
    int mid;
    int k=-1;;

    while(l<=r)
    {
        mid=l+(r-l)/2;
        

        if(diffArrTech(nums,queries,mid)) //if true means possible so move one step back 
        {
            k=mid+1; //as we are storing the number of queries processed so that will be mid+1
            r=mid-1; //now check for,by going one step back 
        }

        else //uptill here not possible move l to mid+1
        {
            l=mid+1;
        }
    }

    return k; //minimum idx
}
 int main()
{
    
    return 0;
}