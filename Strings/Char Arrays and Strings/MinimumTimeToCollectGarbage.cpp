#include <bits/stdc++.h>
using namespace std;

// LC-2391

int garbageCollection(vector<string> &garbage, vector<int> &travel)
{

    int indmetal = -1;
    int indpaper = -1;
    int indglass = -1;

    for (int i = garbage.size() - 1; i >= 0; i--)
    {

        if (garbage[i].find('M') != string::npos) // for metal
            indmetal = max(i, indmetal);

        if (garbage[i].find('P') != string::npos) // for paper
            indpaper = max(i, indpaper);

        if (garbage[i].find('G') != string::npos) // for glass
            indglass = max(i, indglass);

        if (indmetal != -1 && indpaper != -1 && indglass != -1)
            break;
    }

    int totaltime = 0;
    int count = 0;

    // looping for metal truck
    for (int i = 0; i <= indmetal; i++)
    {
        string str = garbage[i];
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'M')
                count++;
        }

        if (i > 0)
            totaltime = totaltime + count + travel[i - 1];

        else
            totaltime = totaltime + count;

        count = 0;
    }

    // looping for paper truck
    for (int i = 0; i <= indpaper; i++)
    {
        string str = garbage[i];
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'P')
                count++;
        }

        if (i > 0)
            totaltime = totaltime + count + travel[i - 1];

        else
            totaltime = totaltime + count;

        count = 0;
    }

    // looping for glass truck
    for (int i = 0; i <= indglass; i++)
    {
        string str = garbage[i];
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'G')
                count++;
        }

        if (i > 0)
            totaltime = totaltime + count + travel[i - 1];

        else
            totaltime = totaltime + count;

        count = 0;
    }

    return totaltime;
}

int garbageCollection(vector<string> &garbage, vector<int> &travel)
{

    int pickM = 0;
    int pickG = 0;
    int pickP = 0;
    // pick time for each garbage

    int indexM = 0;
    int indexG = 0;
    int indexP = 0;
    // last index upto where it is going

    int travelM = 0;
    int travelG = 0;
    int travelP = 0;
    // how much it travelled

    for (int i = 0; i < garbage.size(); i++)
    {
        string current = garbage[i];
        for (int j = 0; j < current.size(); j++)
        {
            if (current[j] == 'M')
            {
                pickM++;
                indexM = i;
            }

            else if (current[j] == 'G')
            {
                pickG++;
                indexG = i;
            }

            else if (current[j] == 'P')
            {
                pickP++;
                indexP = i;
            }
        }
    }

    // calculating travel time with the help of last index obtained
    for (int i = 0; i < indexM; i++)
    {
        travelM = travelM + travel[i];
    }

    for (int i = 0; i < indexG; i++)
    {
        travelG = travelG + travel[i];
    }
    for (int i = 0; i < indexP; i++)
    {
        travelP = travelP + travel[i];
    }

    int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);
    return ans;
}
int main()
{

    return 0;
}