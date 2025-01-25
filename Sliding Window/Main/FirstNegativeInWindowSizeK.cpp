#include <bits/stdc++.h>
using namespace std;
// GFG-In this learnt a concept of deque for storing as the one which would go first would be the one coming out first
// As we had to figure out the first neg element in the question so deque was the best choice to go with

vector<int> FirstNegativeInteger(vector<int> &arr, int k)
{
    vector<int> ans;
    deque<int> deq; // as the first one that would be entering would be the first one to get out

    int i = 0;
    int j = 0;

    while (i < arr.size())
    {
        if (arr[i] < 0)
            deq.push_back(arr[i]);
        // if any negative number is arrived then would be stored int he temp storage

        if (i - j + 1 == k) // means got the window
        {
            if (!deq.empty()) // means it contains elements
                ans.push_back(deq.front());

            else
                ans.push_back(0); // if not then simply push 0

            if (arr[j] < 0) // means before moving forward we have to pop from deq as it was enetered at this position
                deq.pop_front();

            j++;
        }

        i++;
    }

    return ans;
}
int main()
{

    return 0;
}