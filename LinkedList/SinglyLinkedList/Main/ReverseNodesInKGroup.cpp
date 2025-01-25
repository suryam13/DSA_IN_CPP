#include<bits/stdc++.h>
using namespace std;
//SHEET-LC 25
//  void reverseLL(ListNode* head, ListNode* tail, ListNode* toBeNext,
//                    ListNode* toBePrev) {
//         if (head == tail) {
//             head->next = toBeNext;
//             toBePrev->next = head;
//             return;
//         }

//         reverseLL(head->next, tail, head, toBePrev);
//         head->next = toBeNext;
//     }

//     ListNode* reverseKGroup(ListNode* head, int k) {

//         ListNode* temp = head;
//         ListNode* newHead = head;
//         ListNode* toBePrev;
//         ListNode* dummyHead = head;
//         ListNode* dummyTail = new ListNode(-1);
//         bool check = 1;

//         int cnt = 0;

//         while (temp) {
//             cnt++;
//             if (cnt == k) {
//                 ListNode* mover = temp->next;
//                 reverseLL(dummyHead, temp, temp->next, dummyTail);
//                 dummyTail = dummyHead;
//                 dummyHead = mover; // to store the head for next iteration

//                 if (check) {
//                     newHead = temp;
//                     check = 0;
//                 }

//                 temp = mover;
//                 cnt = 0;

//                 // break;
//             }

//             else
//                 temp = temp->next;
//         }
//         return newHead;
//     }
 int main()
{
    
    return 0;
}