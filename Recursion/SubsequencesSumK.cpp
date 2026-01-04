#include <bits/stdc++.h>
using namespace std;
// Striver Recursion

// print the subsequence whose sum is k

// Method 1-calcualting sum at the end once a pattern is obtained
void subsequence1(vector<int> v, int i, int k, vector<int> temp)
{

    if (i == v.size())
    {
        int sum = 0;
        for (auto it : temp)
        {
            sum += it;
        }

        if (sum == k)
        {
            for (auto it : temp)
                cout << it << " ";
            cout << endl;
        }

        return;
    }

    // excluding
    subsequence1(v, i + 1, k, temp);

    // including
    temp.push_back(v[i]);
    subsequence1(v, i + 1, k, temp);
}

// Method 2 passing the sum variable as well

// Note-if u are sending the sum variable without any reference then no problem,but if u are sending by reference then make sure that the sum is subtracted as well from that current position because it will be saved permanently so while backtracking it would give false output
void subsequence(vector<int> v, int i, int k, int sum, vector<int> temp)
{

    if (i == v.size())
    {
        if (sum == k)
        {
            for (auto it : temp)
                cout << it << " ";
            cout << endl;
        }

        return;
    }

    // excluding
    subsequence(v, i + 1, k, sum, temp);

    // including
    temp.push_back(v[i]);
    sum += v[i];
    subsequence(v, i + 1, k, sum, temp);
    // sum-=v[i];//mandatory in case when sum is sent by reference as it would be saved so make sure to subtract from current position as well
}

// Printing only one subsequence
bool subsequence2(vector<int> v, int i, int k, int sum, vector<int> temp)
{

    if (i == v.size())
    {
        if (sum == k)
        {
            for (auto it : temp)
                cout << it << " ";

            cout << endl;
            return true;
        }

        return false;
    }

    // excluding
    if (subsequence2(v, i + 1, k, sum, temp) == true)
        return true;

    // including
    temp.push_back(v[i]);
    sum += v[i];
    if (subsequence2(v, i + 1, k, sum, temp) == true)
        return true;

    return false;
}

// Returning only the count of subsequences
void subsequence3(vector<int> v, int i, int k, int sum, vector<int> temp, int &count)
{

    if (i == v.size())
    {
        if (sum == k)
        {
            count++;
        }
        return;
    }

    // excluding
    subsequence3(v, i + 1, k, sum, temp, count);

    // including
    sum += v[i];
    subsequence3(v, i + 1, k, sum, temp, count);
}

// Returning only the count of subsequences method 2
int subsequence4(vector<int> v, int i, int k, int sum, vector<int> temp, int &count)
{
    if (i == v.size())
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
        
    }

    // excluding
    int r = subsequence4(v, i + 1, k, sum, temp, count);

    // including
    sum += v[i];
    int l = subsequence4(v, i + 1, k, sum, temp, count);

    return l + r;
}
int main()
{

    // int arr[5]={1,2,6,9,1};
    vector<int> v = {1, 2, 6, 9, 1, 2};
    int k = 2;
    vector<int> temp;
    int sum = 0;
    int count = 0;

    // subsequence2(v, 0, k, sum, temp);

    cout << subsequence4(v, 0, k, sum, temp, count);
    ;

    return 0;
}