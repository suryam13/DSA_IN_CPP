#include <bits/stdc++.h>
using namespace std;
//SHEET : LC-85
int histogram(vector<int> &height)
{
    stack<int> st;
    int maxi = INT_MIN;
    for (int i = 0; i < height.size(); i++)
    {
        while (!st.empty() && height[i] < height[st.top()])
        {
            int mainEle = height[st.top()];
            st.pop();
            // as we found the nse as the curr i and pse would be right
            // benath the mainEle

            int leftEle =
                st.empty() ? -1
                           : st.top(); // these are the indices which arr
                                       // stored if nothing then -1 is the
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

        int leftEle =
            st.empty() ? -1
                       : st.top(); // these are the indices which ar stored
        int rightEle =
            height
                .size(); // since there is no nse so considering the extreme

        maxi = max(maxi, mainEle * (rightEle - leftEle - 1));
    }
    return maxi;
}
int maximalRectangle(vector<vector<char>> &matrix)
{

    // creating a 2D matrix which consists of total consecutive 1's upto
    // that axis

    vector<vector<int>> PreSum(matrix.size(), vector<int>(matrix[0].size()));

    // going from column to downwards
    for (int i = 0; i < PreSum[0].size(); i++) // col size
    {
        int sum = 0;
        for (int j = 0; j < PreSum.size(); j++) // row size
        {
            if (matrix[j][i] == '0')
                sum = 0;
            else
                sum +=
                    (matrix[j][i] - '0'); // Convert char to int correctly
            PreSum[j][i] = sum;
        }
    }

    // for (int i = 0; i < PreSum.size(); i++) {
    //     for (int j = 0; j < PreSum[0].size(); j++) {
    //         cout << PreSum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // now using the concept of largest rec in histogram

    int maxi = INT_MIN;

    for (int i = 0; i < PreSum.size(); i++)
    {
        maxi = max(maxi, histogram(PreSum[i])); // giving 1 row at a time
    }

    return maxi;
}
int main()
{

    return 0;
}