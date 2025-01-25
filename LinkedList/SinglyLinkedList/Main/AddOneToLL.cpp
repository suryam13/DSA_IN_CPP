#include <bits/stdc++.h>
using namespace std;
// SHEET-GFG

// THROUGH REVERSAL technique without recursion takes O(3N)
//  void reverse(Node *head, Node *&prev)
//  {
//      if (head == NULL)
//          return;

//     Node *dummy = head->next;
//     head->next = prev;
//     prev = head;
//     reverse(dummy, prev);
// }
// Node *addOne(Node *head)
// {

//     Node *temp = head;
//     Node *prev = NULL;
//     reverse(temp, prev);
//     // prev is pointing to the last of node and acting as a reverse head

//     Node *mover = prev;
//     bool check = 1;

//     while (mover)
//     {
//         if (!check)
//             break;

//         if (mover->data == 9)
//             mover->data = 0;

//         else
//         {
//             mover->data = mover->data + 1;
//             check = 0;
//         }
//         mover = mover->next;
//     }

//     Node *newHead = NULL;
//     reverse(prev, newHead); // reversing again to return node

//     // suppose if everything was 9 9 9 the last would be 0 0 0 so add 1 as a node
//     // to make it look 1 0 0 0
//     if (newHead->data == 0)
//         /
//         {
//             Node *temp = new Node(1);
//             temp->next = newHead;
//             newHead = temp;
//         }
//     return newHead;
// }

// THROUGH RECURSION takes stack space

// void helper(Node* head,int &carry)
// {
//     if(head==NULL) return;

//     helper(head->next,carry);

//     if(head->data==9 && carry==1)
//     {
//         head->data=0;
//         carry=1;
//     }

//     else
//    {
//        head->data=head->data+carry;
//       carry=0;

//    }

// }

// Node* addOne(Node* head) {

//     Node* temp=head;
//     int carry=1;
//     helper(temp,carry);

//     if(head->data==0)
//     {
//         Node *dummy=new Node(1);
//         dummy->next=head;
//         head=dummy;
//     }

//     return head;

// }
int main()
{

    return 0;
}