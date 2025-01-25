#include <bits/stdc++.h>
using namespace std;
/*
Binary Search can be applied on :-
1.Classical questions
2.Predicate Functions
3.index logic
4.search space

*/

//optimal by binary search
//whenever upto a certain point ans is possible and after that it is not possible,in such cases we can surely use binary search
int mySqrt1(int x)
{

    int start = 0;
    int end = x;
    long long int mid = start + (end - start) / 2;
    int ans = 0;

    while (start <= end)
    {
        if (mid * mid == x)
            return mid;

         if (mid * mid > x)
        {
            end = mid - 1;
        }

        else if (mid * mid < x) //if want to return end then can put <= if desired
        {
            ans = mid;
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
    //also u can return end as it will be always pointing to that ans,but cannot return start

    //the end will be moving to the answer which is possible whereas start will be pointing to that  answer which is not possible just above that

    //T.C - O(log x)
}

// naive approach by linear search
int mySqrt2(int x)
{

    int ans = 0;
    for (int i = 0; i <= x; i++)
    {
        if (i * i <= x)
            ans = i;

        else
            break;
    }
    return ans;
}
int main()
{
    int x;
    cout << "enter the number : ";
    cin >> x;

    cout << mySqrt1(x);
    return 0;
}