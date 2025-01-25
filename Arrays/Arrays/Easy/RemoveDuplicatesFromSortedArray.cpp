#include <bits/stdc++.h>
using namespace std;

//LC-26

//  Bruteforce approach takes O(NlogN+N)
//     set<int>st;

//     for(int i=0;i<nums.size();i++)
//     {
//         st.insert(nums[i]); takes log N complexity
//     }

//     int index=0;
//     for(auto it:st)
//     {
//         nums[index]=it;
//         index++;
//     }

//     return index;

// Optimal Solution takes O(N) by two pointer approach
// int i = 0;

// for (int j = 1; j < arr.size(); j++)
// {
//     if (arr[i] != arr[j])
//     {
//         arr[i + 1] = arr[j];
//         i++;
//     }
// }
// return i + 1;

int main()
{

    return 0;
}