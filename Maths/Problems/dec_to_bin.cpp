#include <bits/stdc++.h>
using namespace std;

int bin(int n)
{
    float ans = 0; // float because int not suitable in VS for this
    int i = 0;
    while (n != 0)
    {
        int digit = n & 1;

        ans = digit * pow(10, i) + ans; // to reverse according to compiler,if same according to compiler than the formula is ans=ans*10+digit

        n = n >> 1;
        i++;
    }
    return ans;
}

string decToBinary(int n) {
    string ans;
    while(n>1)  //mae sure it is greater than 1 that is it should be atleast 2
    {
        int mod=n%2;
        char ch='0'+mod;
        ans.push_back(ch);
        n=n/2;
    }
    ans.push_back('0'+n); //pushing the last one
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << bin(n);
    return 0;
}