#include <bits/stdc++.h>
using namespace std;
// SHEET : LC-84

// Another standard appraoch as per observation
int largestRectangleArea(vector<int> &height)
{
    // Next smaller element index (right side)
    vector<int> v(height.size());
    stack<int> st;

    // Calculate the next smaller element index for each bar
    for (int i = height.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && height[i] <= height[st.top()])
            st.pop();

        if (st.empty())
        {
            v[i] = height.size(); // If no smaller element, use size of the array
        }
        else
        {
            v[i] = st.top(); // The next smaller element's index
        }
        st.push(i);
    }

    // Previous smaller element index (left side)
    vector<int> temp(height.size());
    stack<int> st1;

    for (int i = 0; i < height.size(); i++)
    {
        while (!st1.empty() && height[st1.top()] >= height[i])
            st1.pop();

        if (st1.empty())
        {
            temp[i] = -1; // If no smaller element, use -1
        }
        else
        {
            temp[i] = st1.top(); // The previous smaller element's index
        }
        st1.push(i);
    }

    // Now calculate the maximum area
    long long maxi = 0;
    for (int i = 0; i < height.size(); i++)
    {
        int width = v[i] - temp[i] - 1;     // Calculate the width of the rectangle
        long long area = width * height[i]; // Calculate the area
        maxi = max(maxi, area);             // Update maxi with the largest area
    }

    return maxi; // Return the largest area found
}

int largestRectangleArea(vector<int> &height)
{ // Optimal Approach

    // The fact is that i want nse and pse for a particular element to
    // calculate nse-pse-1 and then * height[i] I have to touch every
    // element in order to calculate
    stack<int> st;
    int maxi = INT_MIN;
    for (int i = 0; i < height.size(); i++)
    {
        while (!st.empty() && height[i] < height[st.top()])
        {
            int mainEle = height[st.top()];
            st.pop();
            // as we found the nse as the curr i and pse would be right benath the mainEle

            int leftEle = st.empty() ? -1 : st.top(); // these are the indices which arr stored if nothing then -1 is the
            // pse
            int rightEle = i;

            maxi = max(maxi, mainEle * (rightEle - leftEle - 1));
        }
        st.push(i); // make sure to push the indices of current
    }

    while (!st.empty()) // means there are no nse to that element
    {
        int mainEle = height[st.top()];
        st.pop();

        int leftEle = st.empty() ? -1 : st.top(); // these are the indices which ar stored
        int rightEle = height.size();             // since there is no nse so considering the extreme

        maxi = max(maxi, mainEle * (rightEle - leftEle - 1));
    }
    return maxi;
}
int main()
{

    return 0;
}