#include <bits/stdc++.h>
using namespace std;

//MERGE INTERVAL PATTERN
int countDays(int days, vector<vector<int>> &meetings)
{
    int cnt = 0;

    // whenever we have interval based problems try to sort either on the
    // basis of start or end,here will be sorting on the basis of start of the meeting

    sort(meetings.begin(), meetings.end());

    int start = 0;
    int end = 0;
    for (auto &meet : meetings)
    {
        start = meet[0];

        if (start > end)
            cnt += start - end - 1;

        end = max(end, meet[1]); // always keep a track of max value of end so that we can compare
        // ex : 5    1 5 , 2 2 , 4 5 if we dont keep track of max value of min then at the third iteration
        //  it will be 4 - 2 - 1 = 1 which should not be the thing as 3 is already utilised in 1 5
    }

    cnt += days - end; // count the remaining days if left which are free and not utilised

    return cnt;
}
int main()
{

    return 0;
}