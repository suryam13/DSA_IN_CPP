#include <bits/stdc++.h>
using namespace std;

string clearStars(string s)
{

    // i want the smallest char to the left and id same then the one with the largest idx possible
    int n = s.length();
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    vector<bool> marked(n, false);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            auto top = pq.top();
            pq.pop();
            int idx = abs(top.second); // converting to +ve

            marked[idx] = true; // marking to not take in the answer
        }

        else
            pq.push({s[i], -i});
        // if there are multiple chars smallest on left then i want the one which is super close
        // so inserting negative idx so that comes above in case o two similiar chars
    }

    string ans;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*' || marked[i])
            continue;

        ans.push_back(s[i]);
    }

    return ans;
}


//comparator logic
/*
class Solution {
public:
     struct comp 
        {
            bool operator() ( pair<char,int> p1,pair<char,int> p2)
            {
                if(p1.first == p2.first)
                {
                    return p1.second < p2.second;
                }

                return p1.first>p2.first;
            }
        };

        //in case of priority queue the logic swaps form normal first write the valid one then just swap the directions

    string clearStars(string s) {        
        //i want the smallest char to the left and id same then the one with the largest idx possible
        int n = s.length();

       

        priority_queue< pair<char,int>, vector<pair<char,int>> , comp > pq;
        vector<bool> marked(n,false);

        for(int i=0;i<n;i++)
        {   
            if(s[i] == '*')
            {
                auto top = pq.top();
                pq.pop();
                int idx = abs(top.second); //converting to +ve

                marked[idx] = true; //marking to not take in the answer
            }

            else
            pq.push({s[i],i}); 
            //if there are multiple chars smallest on left then i want the one which is super close 
            //so inserting negative idx so that comes above in case o two similiar chars

        }

        string ans;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='*' || marked[i])
            continue;

            ans.push_back(s[i]);
        }

        return ans;
    }
};
*/
int main()
{

    return 0;
}