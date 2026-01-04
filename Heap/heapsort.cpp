#include <bits/stdc++.h>
using namespace std;

// Heap Sort :
// T.C. O(NlogN)
// S.C. O(1)
// NOTE : the logic of heapify down and perform operation is duplicated i jut merged it so that it becomes easier to understand the workflow

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

void performOperation(vector<int> &v, int size)
{
    size -= 1; // because we dont want to compare with the swapped greater element,larger element moved to its final position.
    int swapIndex = size;
    swap(v[0], v[swapIndex]);

    // now as the smallest has come on top then perform the heapifyDown to maintain the max-heap property;

    int curr = 0;

    while (true)
    {
        int largest = curr;
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;

        if (left < size && v[largest] < v[left])
            largest = left;
        if (right < size && v[largest] < v[right])
            largest = right;

        if (largest == curr)
            break;

        swap(v[curr], v[largest]);
        curr = largest;
    }
}

int main()
{
    vector<int> v = {5, 7, 9, 2, 15, 0};

    // 1st step is to convert it into a max-heap as we want the final answer in ascending order,if we want to have the final answer in descending order then convert into min-heap or either can reverse the answer received my max-heap only but would add extra O(N) for reversing

    convertArrToMaxHeap(v);

    int n = v.size();
    // now i have to perform the modified top and pop operation for n times

    for (int i = 0; i < n; i++)
    {
        performOperation(v, n - i);
        // so now the first time the heapify down for pop operation would go n size then followed by n-1,n-2,..
    }

    for (auto &el : v)
        cout << el << " ";
    cout << endl;

    return 0;
}
