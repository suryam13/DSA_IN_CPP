#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    if (str == "suryam")
        cout << "oh yeah,he's a champ!" << endl;

    else
        cout << "not better than suryam" << endl;

    int num = 3;
    int i = 1;

    do
    {
        cout << i << " ";
        i++;

    } while (i < num);

    return 0;
}