#include<bits/stdc++.h>
using namespace std;

/*
Bruteforce approach T.C -O(N)
2 3 4 7 11  k=5
ans : 9
check if arr[i]<=k then k++ else break
loop till the end of the array

*/

/*
Optimised by binary search
i would have to find between which two indexes my value of k lies as the array is sorted 
with the help of k we can find the count of missing numbers at a particular index by using formulae arr[i]-index-1

eg-2 3 4 7 11
count of missing numbers at each index 1 1 1 3 6
here at 3rd index 4 was supposed to be present as it is sorted in increasing order but eventually 7 is present so to fnd the count of missing numbers uptill here is 7-3-1=3 (1,5,6 are missing).

our motive is to find the 5th missing number which would lie between 7 and 11 as the count between theme ranges from 7 to 11

*/

  int findKthPositive(vector<int>& arr, int k) {

        //optimised
        //firstly i have to find the range of index where my value could lie
        int start=0;
        int end=arr.size()-1;
        int mid=start+(end-start)/2;

        while(start<=end)
        {
            int missing=arr[mid]-(mid+1);

            if(missing<k)
            start=mid+1;

            else
            end=mid-1;

            mid=start+(end-start)/2;
        }
        return start+k;


    }

 int main()
{
    
    return 0;
}