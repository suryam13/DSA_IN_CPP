#include <bits/stdc++.h>
using namespace std;

// LC-485
//to find max number of consecutive appearing 1 in the array

int findMaxConsecutiveOnes(vector<int> &arr)
{

    int count = 0;
    int max_count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
            max_count = max(count, max_count);
        }

        else
            count = 0;
    }
    return max_count;
}

int main()
{

    return 0;
}