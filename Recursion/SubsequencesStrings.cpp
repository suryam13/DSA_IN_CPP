#include <bits/stdc++.h>
using namespace std;

/*
if ouput is to be sent with reference then make sure that it is popped out after pushback in the first case as the data will be permanently saved
else no need to send output that is empty string with reference as it will be managed and consolidated automatically according to the stage of function call
*/
void subsequence(string s, string output, int index) // no need of sending output with reference as we dont want to save the data
{
    if (index == s.size())
    {
        cout << "-->" << output << endl;
        return;
    }

    // here we are excluding first then including
    // exclude
    subsequence(s, output, index + 1);

    // include
    output.push_back(s[index]);
    subsequence(s, output, index + 1);
    // if output is sent by reference then make surre to pop_back after this
    //  output.pop_back();R

    // here we are including first then excluding
    // include
    // output.push_back(s[index]);
    // subsequence(s, output, index + 1);

    // // exclude
    // output.pop_back();
    // subsequence(s, output, index + 1);
}

int main()
{

    string s = "ab";
    string output = " ";

    subsequence(s, output, 0);

    cout << output;

    return 0;
}