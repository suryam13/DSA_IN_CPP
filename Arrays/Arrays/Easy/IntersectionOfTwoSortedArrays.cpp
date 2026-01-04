#include <bits/stdc++.h>
using namespace std;

// coding ninjas
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{

    int i = 0;
    int j = 0;

    vector<int> ans;

//for this in the worst case the T.C. would be O(n1+n2)
//S.C. O(min(n1,n2))
    // this one would work only if the givrn arrays are sorted
    //  while(i<n && j<m)
    //  {
    //  	if(arr1[i]<arr2[j])
    //  	{
    //  		i++;
    //  	}

    // 	else if(arr1[i]==arr2[j])
    // 	{
    // 		ans.push_back(arr1[i]);
    // 		i++;
    // 		j++;

    // 	}

    // 	else if(arr1[i]>arr2[j])
    // 	{
    // 		j++;
    // 	}

    // }

    // this one would work in all the cases
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                arr2[j] = INT_MIN;
                ans.push_back(arr1[i]);
                break;
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}