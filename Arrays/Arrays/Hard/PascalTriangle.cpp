#include <bits/stdc++.h>
using namespace std;
/*
What is a pascal triangle?

                    1
                  1   1
                1   2   1
              1   3    3   1
            1   4    6   4   1


1 at the extreme ends then sum of adjacents in the respective middle of the block

*/

/*
How to find nCr?
brute approach is findindividually all the terms an then perform the respective operations

optimised approach-
strivers approach-

int nCr(int n,int r)
{
    long long res=1;

    for(int i=0;i<r;i++)
    {
        res=res*(n-i);
        res=res/i+1;  doing this to ease the calculations
    }
    return res;
}

mine approach


int nCr(int n,int r)
{
   int num=n;
   int den=r;

   long long numans=1;
   long long denans=1;

   while(den!=0)
   {
        numans=numans*num;
        denans=denans*den;

        num--;
        den--;
   }

    long long res=numans/denans;
    return res;
}


*/

/*
How to print a given single row in pascal triangle?

observation - first element would obviously be 1 but what from 2nd onwards ? it is row-1/1 so we ahve to store it in ans variable and then multiply at each pattern
void printy(int row)
{
int i = row - 1;
int j = 1;
int ans = 1;

//1 4 6 4 1
//6 comes by multiplying what? 4*x=6 so x=3/2 so numerator will be kept on -- and denominator would be ++ and keep multiplying from previous

for (int k = 0; k < row; k++)
{
    if (k == 0)
        cout << "1" << " ";

    else
    {
        ans = ans * i / j;
        cout << ans << " ";
        i--;
        j++;
    }
}
}
*/

/*
How to print entire pascal triangle upto a given row number?

 vector<vector<int>> generate(int numRows) {


        vector<vector<int>> finalans;
        vector<int> dummy;

        for(int i=1;i<=numRows;i++)
        {   
            int numerator=i-1;
            int denominator=1;
            int ans=1;
            for(int j=1;j<=i;j++)
            {
                if(j==1)
                dummy.push_back(1);

                else
                {   
                    
                    ans=ans*numerator/denominator;
                    dummy.push_back(ans);
                    numerator--;
                    denominator++;
                }
            }
            finalans.push_back(dummy);
            dummy.clear();

        }
        return finalans;

        
    }
*/
int main()
{

    /*
        1st question-to give the answer at the specified position
        to find the element at specified row an column pass ncr(row-1,col-1);
    */

    /*
         2nd question-to print the ith row in a pascal triangle
    */

   /*
     3rd question-How to print entire pascal triangle upto a given row number?

   */

    return 0;
}