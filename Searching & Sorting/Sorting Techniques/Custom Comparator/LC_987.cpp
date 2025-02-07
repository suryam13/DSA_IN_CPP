#include<bits/stdc++.h>
using namespace std;
 auto comp=[](pair<int,int> p1,pair<int,int> p2)
          {
                if(p1.first==p2.first)
                return p1.second<p2.second; // sort in ascending order means pehle smaller value aayega
   
                else
                return p1.first<p2.first; //else earlier p1 should be there then p2 as they are not same maintain y-axis order 
          };
 int main()
{
    
    return 0;
}