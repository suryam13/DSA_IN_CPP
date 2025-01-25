#include <bits/stdc++.h>
using namespace std;

/*
brute appraoch-O(N3)


bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}


*/

/*
Better approach-O(NlogN+N)
1st approach(mine)

int longestSuccessiveElements(vector<int>&a) {
    sort(a.begin(),a.end());
        int count=1;
        int longest=1;
        int current=a[0];
        for(int j=1;j<a.size();j++)
        {
            //means it is consecutive
            if(a[j]==current+1)
            {count++;
            current++;
            longest=max(longest,count);
            }


            //to handle the edge case where there ar duplicate values
            else if(a[j]==current)
            {
                continue;
            }

            //if not consecutive then then reset the and the current element
            else if(a[j]!=current+1)
          {
                 count=1;
                current=a[j];

          }

        }

    return longest;

}

//2nd approach
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}
*/

/*
Optimised appraoch

//T.C-O(3N) considering that the unordered map has minimum collisiions and takes constant time
        int n = nums.size();
        if (n == 0)
            return 0;

        int longest = 1;

        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        for (auto it : st) {
            // checking whether previous element exists or not so as to decide
            // whether this is my starting point or not

            if (st.find(it - 1) == st.end()) {
                // means the previous doesnt exist
                int cnt = 1;
                int x = it; // denotes that this is my first element
                while (st.find(x + 1) != st.end()) {
                //here it is not O(n2) because we are iterating till 2N as we are avoiding the specific elements by checking the condition
                    // run the loop untill the next is not present
                    cnt++;
                    x++;
                }
                longest = max(longest, cnt);
                // storing the max sequence
            }
        }

        return longest;
*/
int main()
{

    return 0;
}