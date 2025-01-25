#include <bits/stdc++.h>
using namespace std;

// gfg

/*
bruteforce approach-O(N2)
take two lopps and check whether in the next part any of the elment is greater or not,if not the the element itself is a leader,else not a leader

          vector<int> v;

        for(int i=0;i<n;i++)
        {
           bool isLeader=1
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]<arr[j])
              {
                  isLeader=0;
                  break;

              }
            }
            if(isLeader!=0)
            v.push_back(arr[i]);

        }

      reverse(v.begin(),v.end());  //optional as per the requirement of the solution
      return v;

*/

/*
optimmised-O(N)

           vector<int>ans;
            int maxi = INT_MIN;

            for(int i = n-1;i>=0;i--){
                if(arr[i] >= maxi){
                    ans.push_back(arr[i]);
                    //always store the max term on the right of current
                     maxi = arr[i];
                }

            }

            reverse(ans.begin(), ans.end()); //optional as per the requirement of the solution
            return ans;

*/

int main()
{

    return 0;
}
