#include <bits/stdc++.h>
using namespace std;

//coding ninjas

/*

I've been watching this lecture for the last two days, and it was so frustrating that I couldn't understand the concept, even though Raj Bhaiya explained it thoroughly. After putting in about 7-8 hours, I finally understood what was holding me back. Here's what I've learned:

1. map_name.find(value)-> This function returns an iterator to the element with the key `value` if it is present in the map. If the key is not found, it returns an iterator to `map_name.end()`.

2. map_name.end()-> This function returns an iterator one past the last element of the map. If your map has a size of 4 (indexing from 0 to 3), `map_name.end()` will give you an iterator representing index 4, which is beyond the last element.

3. if(map.find(value) != map.end())-> This line was a real pain in my ass so basically this line checks whether the key `value` is present in the map. If `map.find(value)` does not equal `map.end()`, it means the key is found in the map.similarly , if `map.find(value)` equals `map.end()`, the key is not present in the map.

Understanding this line was crucial for me. The `.find()` function returns an iterator to the element if it is present, or `map.end()` if it is not. So, the condition `if(map.find(value) != map.end())` essentially means, "if the key `value` is found in the map."
*/

/*
Bruteforce approach-O(N)2
would work for +ve,-ve and 0

eg-1 2 3 1 1 1 4 2 3
int sum=0;
int len=0;
for(int i=0;i<n;i++)
{
sum=0;
for(int j=i;j<n;j++)
{
    sum=sum+arr[j];
    if(sum==k)
    {
        len=max(len,j-i+1);
    }
}
}

*/

/*
optimised approach- O(NLogN) S.C-O(N) as hashmap is used


this code is the only optimal solution in case all +,0,-  but can be optimized if there exists only +ve and 0
map<long long, int> mapy;
key is the sum upto the particular index whereas value is the index where it is present

int maxLen = 0;
long long sum = 0;

for (int i = 0; i < nums.size(); i++)
{
    sum = sum + nums[i];

    if (sum == k)
    {
        maxLen = max(maxLen, i + 1);
    }

    int rem = sum - k;

     //check whether is rem in the map before
    if (mapy.find(rem) != mapy.end()) // it means that  rem is present in the hashmap
    {
        int len = i - mapy[rem];
     //subtracting it with the previous index i where rem was present

        maxLen = max(maxLen, len);
    }

    //check whether is sum previously present in the map to avoid the confusion of zero as if it would be present then it would override the previous index and thereby shorten the length of the subarray
    //it means the sum value is not there
    if (mapy.find(sum) == mapy.end()) // means sum is not present in the hashmap so we have to update it
    {
        mapy[sum] = i;
    }
}
return maxLen;
*/

/*
optimised approach in case of positive and zeros is through two pointer t.c. O(2N) s.c. o(1)

the time complexity would not be n-sqaure because in the another nested operation it is not traversing the entire loop again and again instead is going for a certain number of operations or may be going 0 in each iteration



    int right=0;
    int left=0;
    long long sum=a[0];
    int maxlen=0;
    int n=a.size();

    while(right<n)
    {
        while(left<=right && sum>k) if sum is greater than k then discard the previous ones and move left++
        {
            sum-=a[left];
            left++;
        }

        if(sum==k)
        {
            maxlen=max(maxlen,right-left+1);
        }


        right++;

        if(right<n)
        sum+=a[right];
    }
    return maxlen;


*/
int main()
{

    return 0;
}