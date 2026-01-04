#include <bits/stdc++.h>
using namespace std;
// ListNode* detectCycle(ListNode* head) {

//         // Method 1 is to take extra space and solve by keeping the address of
//         // the pointer and index

//         // Method 2 is using tortoise and hare algo
//         /*INTUTION :
//            Suppose the slow pointer moves by k steps and it reaches the point
//            of cycle then obviously the fast would be 2*k steps from the head and
//            the slow would be k steps ahead from the head and fast is k steps
//            ahead from the slow. Now in order to collide with the slow suppose
//            fast is at a distance of x,slow would have to move x steps far and
//            fast would move 2*x in order to collide. The moment when fast
//            collides means it collided at the point x right from where the slow
//            was initially so now the fast and slow pointers are k distance away
//            from the starting loop node So now place the slow at head and iterate
//            both slow anf fast by 1 step the point where they meet is the start
//            of loop

//         */

//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;

//             if (slow == fast) // means they have collided
//             {
//                 slow = head;

//                 while (slow != fast) {
//                     slow = slow->next;
//                     fast = fast->next;
//                 }
//                 return slow;
//             }
//         }
//         return NULL;
//     }
int main()
{

    return 0;
}