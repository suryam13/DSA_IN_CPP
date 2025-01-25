#include<bits/stdc++.h>
using namespace std;


//eg 10 10 2 2 5 5 2 7 7
//at once no element can come more than twice
//observations:
//before the odd occuring element first element is on the even index and second is on odd
//after that index reverse
//ans is on even index

int ans(int arr[],int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while(start<=end)
    {
        if(start==end)
        return start; // to handle single element

        if(mid&1) // if the index of mid is odd
        {
            if( mid-1>=0 && arr[mid-1]==arr[mid])
            start=mid+1;

            else
            end=mid-1;

        }

        else  //in even index
        {
            if(mid+1<n && arr[mid]==arr[mid+1])
            start=mid+2;//because next element is checked so no need of checking again

            else
            end=mid;//as ans is on even index so it can be that also so considering that
        }

        mid = start + (end - start) / 2;
    }
    return -1;
}
 int main()
{   
    int arr[]={10 ,10, 2 , 2 ,1 ,5 ,5 ,7 ,7};
    int n=9;

    cout<<arr[ans(arr,n)];
    
    return 0;
}