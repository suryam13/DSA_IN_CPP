#include <bits/stdc++.h>
using namespace std;

//coding ninjas

// bruteforce approach to use set as it stores unique values
// T.C.  O(N1logN)+O(N2logN)+O(N1+N2)//in worst case where all elements are unique so has to store both the array elements
// S.C. O(n1+n2)(set space)(used to solve the problem) + O(n1+n2)(it is not used to solve the problem,it is the additional vector that is taken to return the answer)

// #include<bits/stdc++.h>
// vector < int > sortedArray(vector < int > a, vector < int > b) {
//    vector<int> v;
//    set<int> st;

//    for(int i=0;i<a.size();i++)
//    {
//        st.insert(a[i]);//takes logN to insert
//    }

//     for(int i=0;i<b.size();i++)
//    {
//        st.insert(b[i]);
//    }

//     for(auto it:st)
//     {
//         v.push_back(it);
//     }
//     return v;

// }

// optimised using two pointer
// T.C. O(n1+n2)
// S.C. O(n1+n2) in worst case where all the elements are unique so would be storing entire elements

#include <bits/stdc++.h>
vector<int> sortedArray(vector<int> a, vector<int> b)
{
    // bruteforce method is use set and use additional vector to return

    int a1 = a.size();
    int b1 = b.size();

    vector<int> v; // to store the values and return this

    int i = 0; // points to array a
    int j = 0; // points to array b

    //firstly we would check if the i value is bigger or same of j then it would be the first to get inserted if j is greater than it would be the first one to get inserted,we are doing this to make sure that the resulting array is sorted in sequence
    while (i < a1 && j < b1)
    {

        if (a[i] <= b[j])
        {
            if (v.size() == 0 || v.back() != a[i])
            {
                v.push_back(a[i]);
            }

            i++;
        }

        else // b[j]>a[i]
        {
            if (v.size() == 0 || v.back() != b[j])
            {
                v.push_back(b[j]);
            }

            j++;
        }
    }

    //in case if the j pointer reaches end but still some are remaining in i pointer then we would insert that entire by continuing to check the back elements
    while (i < a1)
    {

        if (v.size() == 0 || v.back() != a[i])
        {
            v.push_back(a[i]);
        }

        i++;
    }

     //in case if the i pointer reaches end but still some are remaining in j pointer then we would insert that entire by continuing to check the back elements
    while (j < b1)
    {
        if (v.size() == 0 || v.back() != b[j])
        {
            v.push_back(b[j]);
        }

        j++;
    }

    return v;
}
int main()
{

    return 0;
}