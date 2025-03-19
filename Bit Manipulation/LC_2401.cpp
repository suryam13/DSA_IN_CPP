#include <bits/stdc++.h>
using namespace std;

int longestNiceSubarray(vector<int> &nums)
{

    // sliding window + bitmasking
    /*
    The approach is that we have to keep the bit where 1 comes because then the AND operation would not be 0 so keep adding the
    position of the 1 bit by doing an OR operation with the current number to the mask so that the posiitons are been marked
    and if it not zero then break and again start from mask 0
    this would take O(n2) approach

    to store the 1 bit position(bit position where 1 is present) of a number within range do --> mask = mask | nums[j]
    to remove the 1 bit position of a number within range do --> mask = mask ^ nums[j]


    Optimised is through sliding window,when sliding to remove the credentials of ith index just xor that ith number from mask
    O(N)
    */

//     int n = nums.size();
//     int mask = 0;
//     int maxi = 0;

//     for (int i = 0; i < n; i++) {
//         mask=0;
//         for (int j = i; j < n; j++) {
//             if ((mask & nums[j]) == 0) {
//                 // means valid so just add the current j to mask
//                 mask = (mask | nums[j]);
//             }

//             else
//                 break;

//             maxi = max(maxi, j - i + 1);
//         }
//     }
//     return maxi;

    int n = nums.size();
    int mask = 0;
    int maxi = 0;
    int i = 0;
    int j = 0;

    while (j < n)
    {
        while ((mask & nums[j]) != 0)
        {
            // shrink i by doing xor operation,so that i credentials of 1 bit position is been eliminated
            mask = mask ^ nums[i];
            i++;
        }

        maxi = max(maxi, j - i + 1);

        mask = mask | nums[j]; // else everything is alright just store the current j credentials
        j++;
    }
    return maxi;
}
int main()
{

    return 0;
}