#include<bits/stdc++.h>
using namespace std;


/*

Memoization(top-down)

->For applying memoization always make sure that the return type is set to variable(int) and not void
->Try to start from n to 1 because then tabulation becomes much more easier,else no worries
->To apply memoization always check which variables are changing according to each function call then consider that terms to be memoized
in terms of 1D,2D or 3D dp vector
->We do memoization to avoid recomputations so we store the repeating subproblems once and if the condition arises again then we know the answer 
for that so we simply send the stored answer instead of making a recursive call.
-> Initialize the dp array with a dummy value like `-1` (for `int` or `ll`) to know if the value has 
   already been computed.

✍️ Pattern:
    if (dp[i][j] != -1) return dp[i][j];
    // compute and store
    return dp[i][j] = ...;


Tabulation(bottom-up)
here we use for loop and go from 0->n and use previous states to solve the current problems
We initially define the state of the DP and then set few initial values which are already known as per the base case and then do the further 
computations based on previous states 


Space optimization :
after tabualtion there is space optimization which is only possible when our input is depenedent on few previous terms 


NOTE : Whenever doing recursion from 0 to n try to do tabulation from n to 0 as it helps in ease to write the tabulation part
*/
 int main()
{
    
    return 0;
} 