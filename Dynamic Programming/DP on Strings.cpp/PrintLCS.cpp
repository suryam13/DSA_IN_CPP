#include <bits/stdc++.h>
using namespace std;

// SHEET GFG

// recursive method
string helper(string &text1, string &text2, int i, int j, vector<vector<string>> &dp)
{
    if (i == text1.size() || j == text2.size())
        return "";

    if (dp[i][j] != "#") // "#" indicates unvisited
        return dp[i][j];

    if (text1[i] == text2[j])
    {
        // Characters match → include this and move diagonally
        return dp[i][j] = text1[i] + helper(text1, text2, i + 1, j + 1, dp);
    }

    // Explore both options and return the longer string
    string moveI = helper(text1, text2, i + 1, j, dp);
    string moveJ = helper(text1, text2, i, j + 1, dp);

    return dp[i][j] = (moveI.size() > moveJ.size()) ? moveI : moveJ;
}

vector<string> allLCS(string &s1, string &s2)
{

    int m = s1.size();
    int n = s2.size();
    vector<vector<string>> dp(m + 1, vector<string>(n + 1, "#"));
    return {helper(s1, s2, 0, 0, dp)};
}

/*
for this either we can use the tabulation code and iterate from 0,0 where our answer is stored and if the char matches then go to i+1,j+1
or if it doesnt then go to max(i+1,j or i,j+1)

    while(i>=0 && j>=0)
    {
        //computations
    }
*/

// Print all LCS
//GFG
class Solution
{
public:
    // Recursive function to find the length
    //   int helper(string &text1, string &text2,int i,int j,vector<vector<int>> &dp)
    //  {
    //      if(i==text1.size() || j==text2.size())
    //      return 0; //as no char can be compared now amongst two strings

    //     if(dp[i][j] != -1)
    //     return dp[i][j];

    //     if(text1[i] == text2[j]) //means they are same so 1
    //     return 1 + helper(text1,text2,i+1,j+1,dp); //move both the indices forward

    //     //not equal so check by moving both the indices one by one

    //     int moveI = helper(text1,text2,i+1,j,dp);

    //     int moveJ = helper(text1,text2,i,j+1,dp);

    //     return dp[i][j] = max(moveI,moveJ);
    // }

    set<string> res; // to collect unique LCS
    unordered_map<string, bool> memo;

    void backtrack(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, string current)
    {

        // Base case: if we've reached the end of either string

        if (i == s1.size() || j == s2.size())
        {
            res.insert(current);
            return;
        }

        // If characters match, include it and move diagonally,as we wrote the condition
        // in recursive to move to i+1,j+1

        string key = to_string(i) + "," + to_string(j) + "," + current;

        if (memo[key])
            return;

        if (s1[i] == s2[j])
        {
            backtrack(i + 1, j + 1, s1, s2, dp, current + s1[i]);
        }

        else
        {
            // Move in direction(s) that give the max dp value
            if (dp[i + 1][j] > dp[i][j + 1])
            {
                backtrack(i + 1, j, s1, s2, dp, current);
            }

            else if (dp[i + 1][j] < dp[i][j + 1])
            {
                backtrack(i, j + 1, s1, s2, dp, current);
            }

            // means both path has the lcs so explore both
            else
            {
                backtrack(i + 1, j, s1, s2, dp, current);
                backtrack(i, j + 1, s1, s2, dp, current);
            }
        }

        memo[key] = true;
    }

    vector<string> allLCS(string &s1, string &s2)
    {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill DP table (bottom-up)
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        // now as i have got the DP table i will send and explore all the possbilities
        // by following the conditions

        backtrack(0, 0, s1, s2, dp, "");
        return vector<string>(res.begin(), res.end());
    }
};

int main()
{

    return 0;
}