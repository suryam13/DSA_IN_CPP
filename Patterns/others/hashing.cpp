#include<bits/stdc++.h>
using namespace std;

/*
method 1-to count the number of appearences of a specific number by iterating the entire loop and storing that in count variable given that the number which is to be counted is to be provided but thats not possible in all the scenarios.

method 2-creating a hash array of size of the max element+1 from the original array

*/
 int main()
{
    int n;
    cout<<"enter the size of the array : "<<endl;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int maxi=*max_element(arr,arr+n);

    int hashArray[maxi+1]={0};
    for(int i=0;i<n;i++)
    {
        hashArray[arr[i]]++;
    }

    int element;
    cout<<"enter the element of which want the count : "<<endl;
    cin>>element;

    if(element>maxi)
    cout<<"no such entry";

    else
    cout<<hashArray[element];
  

    return 0;
}