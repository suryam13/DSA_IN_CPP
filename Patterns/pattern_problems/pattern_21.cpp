#include <bits/stdc++.h>
using namespace std;

/*
 butterfly pattern

 *      *
 **    **
 ***  ***
 ********
 ********
 ***  ***
 **    **
 *      *



*/

void pattern(int n)
{

    for (int i = 0; i < 2 * n; i++)

    {
        int stars = i+1;
        int spaces=2*n-2*i-2;


        if(i>n-1)
        {
            stars=2*n-i;
            spaces=2*(i-n);
        }

        // for stars
        for (int i = 0; i < stars; i++)
        {
            cout<<"*";
        }

        // for spaces
         for (int i = 0; i < spaces; i++)
        {
            cout<<" ";
        }

         for (int i = 0; i < stars; i++)
        {
            cout<<"*";
        }

        cout<<endl;
    }
}

int main()
{
    int n;
    cout << "enter the value of n : ";
    cin >> n;

    pattern(n);
    return 0;
}