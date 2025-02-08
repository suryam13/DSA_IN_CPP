#include <bits/stdc++.h>
using namespace std;


unordered_map<int, int> idxToVal;          // idx --> value at that idx
unordered_map<int, set<int>> valToIndices; // where they are present storing
                                           // it in ordered set to give min
// value -> set of indices
// NumberContainers() {}

void change(int index, int number)
{

    if (idxToVal.find(index) != idxToVal.end()) // means earlier value ahs to be deleted from the set t
    {
        int num = idxToVal[index]; // which value is to be considered as a key so
                                   // that to delete current idx form that

        valToIndices[num].erase(index);

        if (valToIndices[num].empty())
            valToIndices.erase(num);
    }
    idxToVal[index] = number;
    valToIndices[number].insert(index);
}

int find(int number)
{

    if (valToIndices.find(number) == valToIndices.end())
        return -1;

    auto it = valToIndices[number].begin();
    return *it;
}
int main()
{

    return 0;
}