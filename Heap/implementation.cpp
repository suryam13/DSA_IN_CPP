#include <bits/stdc++.h>
using namespace std;

class maxHeap
{
    vector<int> v;

public:
    // insertion into the heap
    void add(int ele) // for a single element it takes o(logN) for insertion,this process is also known as heapify-up
    {
        v.push_back(ele);

        int lastInd = v.size() - 1;

        int child = lastInd;
        int parent = (lastInd - 1) / 2;

        // if we have reached upto the last index i.e. child == 0 in the worst case,then no need to compare ahead
        while (child > 0 && v[parent] < v[child])
        {
            swap(v[parent], v[child]);
            child = parent;
            parent = (child - 1) / 2;
        }
    }

    void remove() // for a single element it takes o(logN) for deletion of the max element,the process is also known as heapify-down
    {
        // i have to remove the 0th index element but i would swap it with the last element in the array and do a pop_back so in such a case the max element is been removed from the heap and also the property complete binary tree rule is also maintained as we have taken the last element from the tree and placed at the top
        int n = v.size();
        if (n == 0) // nothing to be removed
            return;

        swap(v[0], v[n - 1]);
        v.pop_back();

        n = v.size(); // as popped back so size gets reduced

        // now the next task is to place the 0th index element to its correct positon
        int ind = 0;
        while (true)
        {
            // now i want to insert that element at this particular ind which is the biggest amongst the parent,child1,child2 and repeat the same untill the property is satisifed.
            int maxInd = ind;
            int left = 2 * ind + 1;
            int right = 2 * ind + 2;

            if (left < n && v[maxInd] < v[left]) // only if left child exists
                maxInd = left;
            if (right < n && v[maxInd] < v[right]) // only if right child exists
                maxInd = right;

            if (maxInd == ind) // so no need to change
                break;

            swap(v[maxInd], v[ind]);
            ind = maxInd; // now check whether now at this index it fits better or not by following the process again.
        }
    }

    void print()
    {
        for (auto &el : v)
            cout << el << " ";

        cout << endl;
    }

    void heapifyDown(int curr, vector<int> &v)
    {
        int n = v.size();

        while (true)
        {
            int largest = curr;
            int left = 2 * curr + 1;
            int right = 2 * curr + 2;

            if (left < n && v[largest] < v[left])
                largest = left;
            if (right < n && v[largest] < v[right])
                largest = right;

            if (largest == curr)
                break;

            swap(v[curr], v[largest]);
            curr = largest;
        }
    }

    void convertArrToMaxHeap(vector<int> &v) // optimised
    {
        // would be doing heapify down from the last non-leaf node
        int n = v.size();
        int last = (n / 2) - 1;

        for (int i = last; i >= 0; i--)
        {
            heapifyDown(i, v);
        }
    }
};

int main()
{
    maxHeap H1;
    // H1.add(1);
    // H1.add(2);
    // H1.add(3);
    // H1.add(4);
    // H1.add(5);
    // H1.add(6);
    // H1.print();
    // H1.remove();
    // H1.print();

    vector<int> v = {4, 10, 3, 5, 1};
    H1.convertArrToMaxHeap(v);
    for (auto &el : v)
        cout << el << " ";

    return 0;
}
