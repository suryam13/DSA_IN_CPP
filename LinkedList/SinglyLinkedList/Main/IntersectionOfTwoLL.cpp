#include <bits/stdc++.h>
using namespace std;
// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
// {
//     // Method 1 is to take a set and store the nodes and then compare
//     // Method 2 is to compute the length of both and make them start at
//     // equal NODE by decreasing the longer length node upto it is aligned
//     // with shorter node

//     // ListNode* temp1 = headA;
//     // ListNode* temp2 = headB;

//     // int len1 = 0;
//     // int len2 = 0;
//     // while (temp1) {
//     //     temp1 = temp1->next;
//     //     len1++;
//     // }
//     // while (temp2) {
//     //     temp2 = temp2->next;
//     //     len2++;
//     // }

//     // temp1 = headA;
//     // temp2 = headB;

//     // if (len1 < len2) {
//     //     // means len2 is to be aligned
//     //     int dif = len2 - len1;

//     //     while (dif--) {
//     //         temp2 = temp2->next;
//     //     }

//     //     // now both are aligned
//     //     while (temp1 && temp2) {
//     //         if (temp1 == temp2)
//     //             return temp1;

//     //         temp1 = temp1->next;
//     //         temp2 = temp2->next;
//     //     }
//     // }

//     // else {
//     //     // means len1 is to be aligned or both are equal
//     //     int dif = len1 - len2;

//     //     while (dif--) {
//     //         temp1 = temp1->next;
//     //     }

//     //     // now both are aligned
//     //     while (temp1 && temp2) {
//     //         if (temp1 == temp2)
//     //             return temp1;

//     //         temp1 = temp1->next;
//     //         temp2 = temp2->next;
//     //     }
//     // }

//     // return NULL;

//     // Method 3 Intutuion based
//     ListNode *temp1 = headA;
//     ListNode *temp2 = headB;

//     while (temp1 != temp2)
//     {
//         temp1 = temp1->next;
//         temp2 = temp2->next;

//         if (temp1 == temp2)
//             return temp1;

//         if (temp1 == NULL)
//             temp1 = headB;

//         if (temp2 == NULL)
//             temp2 = headA;
//     }

//     return temp1;
// }
int main()
{

    return 0;
}