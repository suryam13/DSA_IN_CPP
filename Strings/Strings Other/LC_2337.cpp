#include <bits/stdc++.h>
using namespace std;
bool canChange(string start, string target)
{

    /*
    INTUTION-
    came to know that if i ignore all the spaces and then combine the string
 then if the target==start then true else false

    so ignore the spaces
    and if start is L and target is L then i index which is on start has to
 be greater than j to come to left eg- start- L_ target- _L

 and if start is R and target is R then i index which is on start has to be
 less than j to come to right eg- start- _R target- R_

    */

    // doing this part for suppose if the cnt of chars in both are not same
    // then means they cannot be equal so false
    int cnt = 0;
    for (auto it : start)
        if (isalpha(it))
            cnt++;

    for (auto it : target)
        if (isalpha(it))
            cnt--;

    if (cnt != 0)
        return false;

    int i = 0;
    int j = 0;
    int n = start.size();

    while (i < n && j < n)
    {
        while (start[i] == '_')
            i++; // ignoring spaces
        while (target[j] == '_')
            j++; // ignoring spaces

        if (start[i] != target[j])
            return false; // as per intution

        else if (start[i] == 'L' && i < j) // eg- start- L_ target- _L
            return false;

        else if (start[i] == 'R' && i > j) // eg- start- _R target- R_
            return false;

        i++;
        j++;
    }
    return true;

    // The below approach gave me tle so referred to optimised

    //        bool check = 0;

    // void target_RL(string& start, int i) {

    //     check = 0;

    //     for (int j = i; j < start.size(); j++) {
    //         // if (j == i)
    //         //     continue;

    //         if (start[j] == 'R') {
    //             check = 1;
    //             break;
    //         }

    //         if (start[j] == 'L') {
    //             swap(start[i], start[j]);
    //             break;
    //         }
    //     }
    // }

    // void target_L(string& start, int i) {

    //     check = 0;

    //     for (int j = i; j < start.size(); j++) {
    //         // if (j == i)
    //         //     continue;

    //         if (start[j] == 'R') {
    //             check = 1;
    //             break;
    //         }

    //         if (start[j] == 'L') {
    //             swap(start[i], start[j]);
    //             break;
    //         }
    //     }
    // }

    // void targetR_(string& start, int i) { // means target is _ and
    // current is R

    //     check = 0;

    //     for (int j = i; j < start.size(); j++) {
    //         // if (j == i)
    //         //     continue;

    //         if (start[j] == 'L') {
    //             check = 1;
    //             break;
    //         }

    //         if (start[j] == '_') {
    //             swap(start[i], start[j]);
    //             break;
    //         }
    //     }
    // }
    // the above is function part outside one

    // int i = 0;

    // while (i < start.size()) {

    //     // if equal then no problem go ahead
    //     if (start[i] == target[i]) {
    //         i++;
    //         continue;
    //     }

    //     // dealing with R at target index
    //     else if (start[i] != target[i] && target[i] == 'R' &&
    //              start[i] == 'L') {
    //         return false;
    //     }

    //     else if (start[i] != target[i] && target[i] == 'R' &&
    //              start[i] == '_') {
    //         return false;
    //     }

    //     // dealing with L at target index
    //     else if (start[i] != target[i] && target[i] == 'L' &&
    //              start[i] == 'R') {
    //         target_RL(start, i);
    //         if (check)
    //             return 0;
    //     }

    //     else if (start[i] != target[i] && target[i] == 'L' &&
    //              start[i] == '_') {
    //         target_L(start, i);
    //         if (check)
    //             return 0;
    //     }

    //     // dealing with _ at target index
    //     else if (start[i] != target[i] && target[i] == '_' &&
    //              start[i] == 'L') {

    //         return 0;
    //     }

    //     else if (start[i] != target[i] && target[i] == '_' &&
    //              start[i] == 'R') {

    //         targetR_(start, i);
    //         if (check)
    //             return 0;
    //     }
    //     i++;
    // }

    // return true;
}
int main()
{

    return 0;
}