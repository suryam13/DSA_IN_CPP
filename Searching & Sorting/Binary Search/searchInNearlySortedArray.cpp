#include<bits/stdc++.h>
using namespace std;
//nearly sorted array are the ones where i can be present either on i-1 or i ot i+1 in comparison with the fuly sorted array 

int search(int arr[],int n,int target)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;

    while(start<=end)
    {   
        if(arr[mid-1]==target && mid-1>=0)
        return mid-1;

        else if(arr[mid]==target)
        return mid;

        else if(arr[mid+1]==target && mid+1<n)
        return mid+1;

        else if(target>arr[mid])
        start=mid+2;//right

//+2 and -2 because we want to go behind and do not compare the same mid-1 or mid+1 element again as we have compared them in the starting two cases
        else
        end=mid-2;//left

        mid=start+(end-start)/2;

    }
    return -1;
}

 int main()
{
    int arr[]={20,10,30,50,40,70,90};
    int n=7;
    int target=1000;

    cout<<search(arr,7,target);
    
    return 0;
}