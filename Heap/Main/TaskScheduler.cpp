#include <bits/stdc++.h>
using namespace std;

//LC 621
int leastInterval(vector<char> &tasks, int n)
{

    // the key is that the same chars can't be beside each other as they have to wait the cooling time
    // we have to choose greedily try to finish those tasks which have higher frequency so as to reduce the
    // idleness of the CPU
    // pop n+1 elments from the queue because since the cooling time is n so we have to accomodate that spaces

    priority_queue<int, vector<int>> pq; // max heap
    unordered_map<char, int> mapy;

    for (auto &ch : tasks)
        mapy[ch]++;

    // storing the pair in priority queue
    for (auto &it : mapy)
    {
        pq.push(it.second);
    }
    int time = 0;

    while (!pq.empty())
    {
        // pop n+1 elements
        int rem = n + 1;
        vector<int> store;
        while (!pq.empty() && rem--)
        {
            int freq = pq.top();
            pq.pop();
            freq--;

            store.push_back(freq);
        }

        for (auto &val : store)
        {
            if (val > 0)
                pq.push(val);
        }

        if (pq.empty())
            time += store.size();

        else
            time += n + 1;
    }

    return time;
}
int main()
{

    return 0;
}