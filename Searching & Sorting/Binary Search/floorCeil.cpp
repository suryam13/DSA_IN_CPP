#include<bits/stdc++.h>
using namespace std;


//GFG
int floor(vector<int> &v, int n, int x)  //the values which are lesser than or equal to value x
    {
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        int ans=-1;
        
        while(start<=end)
        {
            if(start==end)
            {
                if(v[start]<=x)
                return v[start];
                
                else 
                return ans;
            }
            
            if(v[mid]==x)
            return v[mid];   //if found on mid then return
            
            else if(v[mid]<x)
            {
                ans=v[mid];
                start=mid+1; //if less than,then too store the result
            }
            
            else if(v[mid]>x)
            end=mid-1;   //move backwards as it is greater
            
            mid=start+(end-start)/2;
        }
        return ans;
    }
    
    int ceil(vector<int> &v, int n, int x)   //the values which are greater than or equal to value x
    {   
        

        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        int ans=-1;
        
        while(start<=end)
        {
            if(start==end)
            {
                if(v[start]>=x)
                return v[start];
                
                else 
                return ans;
            }
            
            if(v[mid]==x)
            return v[mid];   //if found on mid then return
            
            else if(v[mid]>x)
            {
                ans=v[mid];
                end=mid-1; //if greater than,then too store the result
            }
            
            else if(v[mid]<x)
            start=mid+1;   //move forward as it is lesser
            
            mid=start+(end-start)/2;
        }
        return ans;
    }
    
    




pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
    pair<int,int> p;
    p.first=floor(a,n,x);
    p.second=ceil(a,n,x);
    return p;
}

 int main()
{
    
    return 0;
}