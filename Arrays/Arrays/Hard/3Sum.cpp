#include<bits/stdc++.h>
using namespace std;

/*
brute approach-O(N3 x NlogN) which is for sorting and can be considered negligible so as to sort three times which is better as constant
S.C-O(2xno.of triplets)

vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
*/

    vector<vector<int>> threeSum(vector<int>& arr) {

        // // Approach 1
        // T.C.O(N^3)
        // S.C.O(N^3)

        // set<vector<int>> st;

        // for (int i = 0; i < arr.size(); i++) {

        //     for (int j = i + 1; j < arr.size(); j++) {

        //         for (int k = j + 1; k < arr.size(); k++) {
        //             if (arr[i] + arr[j] + arr[k] == 0) {
        //                 vector<int> temp = {arr[i], arr[j], arr[k]};
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }

        // vector<vector<int>> ans(st.begin(), st.end());

        // return ans;

        // Approach 2
        // using map
        // T.C.O(N^2) sorting wont take time as only 3 elements are there
        // S.C-worst case O(N3) if the set consists of all triplets which are
        // unique
        //     unordered_map<int, int> mapy;
        //     set<vector<int>> st;

        //     for (auto& it : arr) {
        //         mapy[it]++;
        //     }

        //     for (int i = 0; i < arr.size(); i++) {

        //         for (int j = i + 1; j < arr.size(); j++) {

        //             int req = -(arr[i] + arr[j]); // in order to generate 0

        //             mapy[arr[i]]--; // to ensure that we are not using the
        //             current
        //                             // element twice
        //             mapy[arr[j]]--; // same as above

        //             if (mapy[req] > 0) // means there exists
        //             {
        //                 vector<int> temp{arr[i], arr[j], req};
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }

        //             mapy[arr[i]]++;
        //             mapy[arr[j]]++;
        //         }
        //     }

        //     vector<vector<int>> ans(st.begin(), st.end());
        //     return ans;
        // }

        // Approach-3 using pointers
        // aim would be to remove the usage of set

        vector<vector<int>> ans;

        sort(arr.begin(), arr.end()); // sorting prior to remove duplicates

        int i = 0;

        while (i < arr.size()) {
            // initially i would be fixed
            int j = i + 1;
            int k = arr.size() - 1;

            if (i > 0 && arr[i - 1] == arr[i]) {
                i++;
                continue;
            }

            while (j < k) {

                if (arr[i] + arr[j] + arr[k] > 0)
                    k--;

                else if (arr[i] + arr[j] + arr[k] < 0)
                    j++;

                else // means are equal
                {
                    vector<int> temp{arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    // now move j and k if previous are equal as they would owe
                    // the same result
                    while (arr[j - 1] == arr[j] && j < k)
                        j++;
                    while (arr[k + 1] == arr[k] && k > j)
                        k--;
                }
            }
            i++;
        }

        return ans;
    }
 int main()
{
    
    return 0;
}