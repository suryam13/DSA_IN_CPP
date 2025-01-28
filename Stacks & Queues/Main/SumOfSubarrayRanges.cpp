#include <bits/stdc++.h>
using namespace std;
// SHEET LC:2104
class Solution
{
public:
    // Note we have to find the indexes so store indexes int he stack
    // We typically use 1LL in the answer because when 2 int are mutliplied they would give error if they are out of range
    // either u set the 2 variables which are to be multiplied to be long long or multiply with 1LL while doing computations
    vector<int> nextGreater(vector<int> &v)
    {

        vector<int> temp(v.size());
        stack<int> st;

        for (int i = v.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && v[st.top()] <= v[i])
                st.pop();

            if (st.empty())
                temp[i] = v.size();

            else
                temp[i] = st.top();

            st.push(i);
        }

        return temp;
    }

    vector<int> prevGreaterEqual(
        vector<int> &
            v)
    { // here we have to stop when we find equal so as to avoid the
      // issue of duplicates eg 1 1 as 1 1 subarray would be
      // considered twice if not taken care
        vector<int> temp(v.size());
        stack<int> st;

        for (int i = 0; i < v.size(); i++)
        {
            while (!st.empty() && v[st.top()] < v[i])
                st.pop();

            if (st.empty())
                temp[i] = -1;

            else
                temp[i] = st.top();

            st.push(i);
        }

        return temp;
    }

    long long GreaterElSum(vector<int> &v)
    {
        vector<int> v1 = nextGreater(v);
        vector<int> v2 = prevGreaterEqual(v);

        long long ans = 0;

        for (int i = 0; i < v.size(); i++)
        {
            long long getNextGreaterIdx = v1[i] - i; // next smaller
            long long getPrevGreaterIdx = i - v2[i]; // prev smaller

            ans = ans + (v[i] * getNextGreaterIdx * getPrevGreaterIdx);
        }

        return ans;
    }

    vector<int> nextSmaller(vector<int> &v)
    {
        vector<int> temp(v.size());
        stack<int> st;

        for (int i = v.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && v[st.top()] >= v[i])
                st.pop();

            if (st.empty())
                temp[i] = v.size();

            else
                temp[i] = st.top();

            st.push(i);
        }

        return temp;
    }

    vector<int>
    prevSmallerEqual(vector<int> &v)
    { // here we have to stop when we find
      // equal so as to avoid the
        // issue of duplicates eg 1 1 as 1 1 subarray would be
        // considered twice if not taken care
        vector<int> temp(v.size());
        stack<int> st;

        for (int i = 0; i < v.size(); i++)
        {
            while (!st.empty() && v[st.top()] > v[i])
                st.pop();

            if (st.empty())
                temp[i] = -1;

            else
                temp[i] = st.top();

            st.push(i);
        }

        return temp;
    }

    long long SmallerElSum(vector<int> &v)
    {
        vector<int> v1 = nextSmaller(v);
        vector<int> v2 = prevSmallerEqual(v);

        long long ans = 0;

        for (int i = 0; i < v.size(); i++)
        {
            long long getNextSmallerIdx = v1[i] - i; // next smaller
            long long getPrevSmallerIdx = i - v2[i]; // prev smaller

            ans = ans + (v[i] * getNextSmallerIdx * getPrevSmallerIdx);
        }

        return ans;
    }

    long long subArrayRanges(vector<int> &nums)
    {

        return (GreaterElSum(nums) - SmallerElSum(nums));

        /*
        Figure out  how many times a particular element is contributing to the
        answer whether it is maximum or minimum

        eg 1 2 3 the possible subarrays would be n*n+1/2 we have to ignore
        single element as it would contribute to 0

            1 2
            1 2 3
            2 3

            here,
            maximumness 3:2 2:1 3*2+2*1=8
            minimumness 1:2 2:1 1*2+2*1=4
            -->8-4=4

            Final answer is supposed to be 4
            For finding maximum count of a particular element we have to find
        next greater and previous greater And for minimum count have to find
        next smaller and prev smaller as the currenet element has to be minimum
        for that many numbers
        */
    }
};

int main()
{

    return 0;
}
