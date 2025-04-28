#include<bits/stdc++.h>
using namespace std;

long long justGreater(vector<int>& nums, int end, int num) {
    int low = 0;
    int high = end - 1;
    int mid;
    long long range = INT_MIN;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (nums[mid] <= num) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
            range = mid; // this could be the just greater idx
        }
    }

    if (range == INT_MIN) // means no just greater found so consider entire range
        return end;

    return range;
}

long long justSmaller(vector<int>& nums, int end, int num) {
    int low = 0;
    int high = end - 1;
    int mid;
    long long range = INT_MIN;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (nums[mid] < num) {
            // could be the possible answer
            range = mid;
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    if (range == INT_MIN) // means no elements to be discarded
        return 0;

    return range + 1;
}
long long countFairPairs(vector<int>& nums, int lower, int upper) {

    long long cnt = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 1; i < n; i++) {
        // start from 1 as the idx 0 would never form any pair with backward
        // elements as this is the starting one
        long long BS_1 = justGreater(nums, i, upper - nums[i]); // would give the big range
        long long BS_2 = justSmaller(nums, i, lower - nums[i]); // would give the smaller range which has
        // to be discarded

        cnt += BS_1 - BS_2; // bigger range - samller range (to be discarded)
    }
    return cnt;

}
 int main()
{
    
    return 0;
}