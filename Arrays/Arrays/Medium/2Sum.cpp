#include <bits/stdc++.h>
using namespace std;
// leetcode-1
// coding ninjas
//  bruteforce aapproach is O(n2) by using two loops

// better is by using hashmap which would take O(NlogN) ahle using ordered map whereas in unordered map it would take O(N) and O(N2) in worst case
// but would take extra space due to map

// vector<int> twoSum(vector<int> &nums, int target)
// {

//     // vector<int> v;
//     map<long long, int> mapy;
//     long long rem = 0;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         rem = target - nums[i];

//         if (mapy.find(rem) != mapy.end())
//         {
//             // v.push_back(i);
//             // v.push_back(mapy[rem]);
//             return {i, mapy[rem]};
//         }

//         if (mapy.find(nums[i]) == mapy.end())
//             mapy[nums[i]] = i;
//     }
//     return {-1, -1};
// }

// optimal approach if only yes or no is needed because it cannot return index as after sorting the indexes would be shuffled,else the better is the only optimal
// used this just to eliminate extra space
//    sort(book.begin(),book.end());

//   int left=0;
//   int right=book.size()-1;

//   while(left<right)
//   {
//       int sum=book[left]+book[right];

//       if(sum==target)
//       return "YES";

//       if(sum>target)
//       right--;

//       else
//       left++;
//   }
//   return "NO";

int main()
{

    return 0;
}