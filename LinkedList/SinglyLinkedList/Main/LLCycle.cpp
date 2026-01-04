#include <bits/stdc++.h>
using namespace std;
//LC-141
// class Solution
// {
// public:
// bool hasCycle(ListNode *head)
// {

// Method-1 By extra space
//  map<ListNode*,int> mapy;

// ListNode* temp = head;

// while (temp) {
//     mapy[temp]++;
//     if(mapy[temp]>1) return true;
//     temp = temp->next;
// }
// return false;

// Method 2-Tortoise and Hare
// ListNode *slow = head;
// ListNode *fast = head;

// while (fast != NULL && fast->next != NULL)
// {
//     slow = slow->next;
//     fast = fast->next->next;
//     if (fast == slow)
//         return true;

//     // if there is a loop then the fast would be approaching slow by 2
//     // steps and sow would move away from fast by 1 step so the overall
//     // distance would be minimised by 1 between slow and fast at every
//     // iteration and at the end they would collide
// }
// return false;

// Method 3 - My method:)

// ListNode* temp = head;

// while (temp) {
//     if (temp->val == INT_MIN)
//         return true;
//     temp->val = INT_MIN;
//     temp = temp->next;
// }
// return false;
// }
int main()
{

    return 0;
}