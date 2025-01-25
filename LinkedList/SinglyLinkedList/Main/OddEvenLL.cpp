#include <bits/stdc++.h>
using namespace std;
// SHEET LC-328
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *oddEvenList(ListNode *head)
{

    int pos = 0;

    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return head;

    ListNode *odd = head;

    ListNode *even = head->next;

    ListNode *connector = head->next; // to store the even address in order
                                      // to link the last odd

    ListNode *temp = head->next->next; // for traversing from 3rd node

    while (temp)
    {
        pos++;

        if (pos % 2 == 1) // means odd node
        {
            odd->next = temp;
            odd = temp;
        }

        else // means even node
        {
            even->next = temp;
            even = temp;
        }

        temp = temp->next;
    }

    odd->next = connector;
    even->next = NULL; // essential as if not then it would make cyclic
                       // causing runtime error

    return head;
}

// or could use this approach
ListNode *oddEvenList1(ListNode *head)
{
    if (!head || !head->next)
        return head; // Handle edge cases: empty list or single node

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even; // Save the head of the even list

    while (even && even->next)
    {
        odd->next = even->next; // Link odd nodes
        odd = odd->next;        // Move the odd pointer

        even->next = odd->next; // Link even nodes
        even = even->next;      // Move the even pointer
    }

    odd->next = evenHead; // Connect the odd list to the even list
    return head;
}
int main()
{

    return 0;
}