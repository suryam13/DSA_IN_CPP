#include<bits/stdc++.h>
using namespace std;
//divide and give using binary search
//dividend=divisor*quotient+remainder
//dividend>=divisor*quotient
// O(logN),where n is the dividend

int getQuotient(int dividend,int divisor)
{
    int start=0;
    int end=dividend;
    int mid=start+(end-start)/2;
    int ans=0;

    while(start<=end)
    {   
        if((mid*divisor)==dividend)
        return mid;


        if((mid*divisor)<dividend)
        {
            ans=mid;
            start=mid+1;
        }

        else
        end=mid-1;

        mid=start+(end-start)/2;

    }
    return ans;
}

 int main()
{   
    cout<<getQuotient(2,7);
    //for negative can use abs function and after ans is returned change sign
    
    return 0;
}