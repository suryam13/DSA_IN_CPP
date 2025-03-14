#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

    //let x be repeated and y be missing

      int n = grid.size();
      long long num=n*n;
      long long sum = (num*(num+1))/2; //sum of n natural numbers
      long long gridSum=0;
      long long sqSum=(num*(num+1)*(2*num+1))/6; //sum of n^2 of n natural number
      long long gridSqSum=0;

      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
            gridSum+=grid[i][j];
            gridSqSum+=grid[i][j]*grid[i][j];
        }
      }

      int x = (((gridSqSum-sqSum)/(gridSum-sum)) + (gridSum - sum))/2;

      int y = x - (gridSum - sum);
      // either can do this
      //   int y = (((gridSqSum-sqSum)/(gridSum-sum)) - (gridSum - sum))/2;


      return {x,y};
    }

     /*
        Explanation : 
        let grid={1,2,2,3}  n=4   x=2(repeating)  y=4(missing)

        gridsum = 1 + 2 + 2 + 3
        sum = 1 + 2 + 3 + 4 
        what if i add subtract 2 in gridSum and add 4 then it would be equal to sum
        i.e gridSum - x + y  = sum
        gridSum - sum = x - y --> eq 1

        similiarly take the same for sqaures

        gridSqSum = ....
        sqSum = .....

        gridSqSum - sqSum = x^2 - y^2
        gridSqSum - sqSum = (x-y) (x+y) 
        we have the value of x-y so divide by that 

        (gridSqSum - sqSum) / (gridSum - sum) = (x+y)  --> eq 2

        now solve that simultaneously
        add 1 and 2

        x =  (((gridSqSum-sqSum)/(gridSum-sum)) + (gridSum - sum))/2;

        subtract 1 from 2
        y =  (((gridSqSum-sqSum)/(gridSum-sum)) - (gridSum - sum))/2

        or just simply do 

        y = x - (gridSum - sum)
    
    */
 int main()
{
    
    return 0;
}