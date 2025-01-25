#include<bits/stdc++.h>
using namespace std;

 int main()
{
    int num=10;
    int k=2;
    int mask=1;

    int l=k;

    // while(l!=0)
    // {
    //     mask=mask<<1;
    //     l--;
    // }

     mask=mask<<k; //alternate method

    cout<<mask<<endl;
    int ans=(num|mask);
    cout<<ans;

    return 0;
}