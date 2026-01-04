#include <bits/stdc++.h>
using namespace std;

string pushDominoes(string dominoes)
{

    // from the observation we found out that we have to find the nearest left domino coming from the
    // right side and right domino coming from the left side for a particular idx if the net distance is
    //  same then domino remains intact else bends towards the one opposite the one which has smallest
    // distance

    int n = dominoes.size();
    // going from left to right to get the right domino which is going to have force
    vector<int> RightEffect(dominoes.size(), -1);
    int righty = -1;
    for (int i = 0; i < n; i++)
    {
        if (dominoes[i] == '.')
            RightEffect[i] = righty;

        else if (dominoes[i] == 'R') // no effect
        {
            RightEffect[i] = -1;
            righty = i; // keep track of recent righty
        }

        else //'L no effect
        {
            RightEffect[i] = -1;
            righty = -1;
        }
    }

    // going from right to left to get the left domino which is going to have force
    vector<int> LeftEffect(dominoes.size(), -1);
    int lefty = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dominoes[i] == '.')
            LeftEffect[i] = lefty;

        else if (dominoes[i] == 'L') // no effect
        {
            LeftEffect[i] = -1;
            lefty = i; // keep track of recent righty
        }

        else //'L no effect
        {
            LeftEffect[i] = -1;
            lefty = -1;
        }
    }

    string ans;

    for (int i = 0; i < n; i++)
    {
        // for a particular idx calculate whats the min distance force which is action ont that

        if (RightEffect[i] == -1 && LeftEffect[i] == -1) // remain as it is
            ans.push_back(dominoes[i]);

        else if (RightEffect[i] == -1)
            // means the 'L' is dominant
            ans.push_back('L');

        else if (LeftEffect[i] == -1)
            // means the 'R' is dominant
            ans.push_back('R');

        else
        {
            // now check which has the minimum distance
            int leftDist, rightDist;
            leftDist = abs(i - LeftEffect[i]);
            rightDist = abs(i - RightEffect[i]);

            if (leftDist > rightDist)
                // means right is smaller
                ans.push_back('R');

            else if (leftDist < rightDist)
                // means left is smaller
                ans.push_back('L');

            else
                // as it is
                ans.push_back(dominoes[i]);
        }
    }

    return ans;
}
int main()
{

    return 0;
}