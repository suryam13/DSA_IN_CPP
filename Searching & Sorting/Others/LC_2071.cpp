#include <bits/stdc++.h>
using namespace std;


bool possible(vector<int> &tasks, vector<int> &workers, int pills, int strength, int mid)
{
    multiset<int> st(workers.begin(), workers.end()); // using this as we can have duplicate strengths

    for (int i = mid - 1; i >= 0; i--)
    {
        auto worker = prev(st.end()); // want the strongest worker just before end as it would be pointing to NULL
        if (tasks[i] <= *worker)
            st.erase(worker);

        else if (pills > 0) // means have to use the pill cleverly
        {
            auto lower = st.lower_bound(tasks[i] - strength); // gives >= the value
            if (lower == st.end())
                return 0;

            st.erase(lower);

            pills--;
        }

        else
            return 0;
    }
    return 1;
}
int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
{

    sort(tasks.begin(), tasks.end());
    // want to make the strongest workers to do the weakest task,i.e from the end tasks
    // would be taken and if the strongest worker is not able to do the strongest task then
    // he has to take a pill so make sure that the worker with minimum strength on taking pill
    // is selected to complete the task

    // we will be using B.S. to identify whether how many task is possible to perform
    int m = tasks.size();
    int n = workers.size();
    int cnt = 0;
    int l = 0, r = min(m, n);

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (possible(tasks, workers, pills, strength, mid))
        {
            cnt = mid;
            l = mid + 1; // chek for more
        }

        else
        {
            r = mid - 1;
        }
    }

    return cnt;
}
int main()
{

    return 0;
}