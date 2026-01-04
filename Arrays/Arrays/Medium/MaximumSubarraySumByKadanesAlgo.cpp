#include <bits/stdc++.h>
using namespace std;

/*
to find the subarray with maximum sum we can apply kadanes algorithm
it states that while going linearly if the sum is negative then change it to 0 and store the max sum in any maxi container
T.C.-O(n)


int sum=0;
int maxi=INT_MIN;
for(int i=0;i<n;i++)
{
    sum=sum+arr[i];
    maxi=max(sum,maxi)

    if(sum<0)
    sum=0;

}
return maxi;


long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum=0;
    long long maxi=LONG_MIN;
    int genstart=-1;
    int substart=-1;
    int subend=-1;

    for(int i=0;i<arr.size();i++)
    {
        if(sum==0)
        genstart=i;//becuase whenever sequence starts it would keep a track


        sum=sum+arr[i];

        if(sum>maxi) //if it is maximum then it would update accordingly pointing to the last index of the subarray as i
        {
         maxi=sum;
         substart=genstart;
         subend=i;
        }

        if(sum<0)
      {
       sum=0;
      }
    }

    //this is optional,needs to be done as per the problem
    if(maxi>0)
    return maxi;

    return 0;
}

now the follow up question is if we are asked to print the subarray then,do the index steps as shown above
*/
int main()
{

    return 0;
}