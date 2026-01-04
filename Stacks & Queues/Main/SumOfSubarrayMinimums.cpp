#include<bits/stdc++.h>
using namespace std;
 vector<int> NextSmallIdx(vector<int>& dummy) {
        vector<int> ans(dummy.size());
        stack<int> st;
        int size=dummy.size();


        //here we are strictly considering lesser element 
        for (int i = dummy.size() - 1; i >= 0; i--) {
            
            
            while (!st.empty() && dummy[st.top()] >= dummy[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = dummy.size(); // means there doesnt exist any next
                                       // smaller element

            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    //here we are going uptill a condition where equal comes then we have to stop as there is a issue in duplicates 
    //becuase one has to be in this condition  consider eg 1 3 1 we are considering the subarray 131 twice in the answer so to avoid it we are going uptill equal only when equal comes we have to stop
    vector<int> PrevSmallOrEqualIdx(vector<int>& dummy) {

        vector<int> ans(dummy.size());
        stack<int> st;

        for (int i = 0; i < dummy.size(); i++) {

            while (!st.empty() && dummy[st.top()] > dummy[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1; // means there doesnt exist any next
                             // smaller element

            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        int mod = 1e9 + 7; // the overflow in int happens on storing 1e9+10
        long long cnt=0;

        /*
        In this i have to take the next smaller element index and the next
        greater element index and when i will multiply that i would get the
        number of subarrays where that element is the minimum
        */

        vector<int> NextSmall = NextSmallIdx(arr);
        vector<int> PrevSmall = PrevSmallOrEqualIdx(arr);
        for(auto it:PrevSmall) cout<<it<<" ";
        for(int i=0;i<arr.size();i++)
        {
            long long  get_prevIdx=i-PrevSmall[i];
            long long  get_nextIdx=NextSmall[i]-i;

            // cout<<i<<" "<<get_prevIdx<<" "<<get_nextIdx<<endl;

            cnt = (cnt + (get_prevIdx*get_nextIdx* arr[i]) % mod)%mod;
            // cout<<cnt<<endl;

        }
        return cnt;
    }
 int main()
{
    
    return 0;
}