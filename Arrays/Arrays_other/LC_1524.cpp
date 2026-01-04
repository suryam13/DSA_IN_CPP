#include<bits/stdc++.h>
using namespace std;
int M=1e9+7;
int numOfSubarrays(vector<int>& arr) {

    //The key is that odd+even=odd and even+odd=odd

    //keep track of even count in prefix sum if it appears odd then means the previous even 
    //collectively can make the overall sum odd 

    int odd_count=0; //if even comes then pair it with number of odds before
    int even_count=1; //because when added with odd odd itself can be an odd sum

    int sum=0;
    int ans=0;

    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];

        if(sum&1) //means odd --> odd + even =odd
        {
            odd_count++;
            ans=(ans+even_count)%M;
        }

        else //means even -->even + odd = odd
        {
            even_count++;
            ans=(ans+odd_count)%M;
        }
    }
    return ans;


    
}
 int main()
{
    
    return 0;
}