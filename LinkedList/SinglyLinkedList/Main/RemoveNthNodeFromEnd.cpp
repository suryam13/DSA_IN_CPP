#include <bits/stdc++.h>
using namespace std;
// LC-19 SHEET
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{

    // Method 1 is to count the nodes and then again go till size - n but
    // would take two pass

    ListNode *fast = head;
    ListNode *slow = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    } // moving the fast pointer to that count

    if (fast == NULL) // means head is to be deleted
        return head->next;

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode *del = slow->next;
    slow->next = slow->next->next;
    delete del; // deleting the node to free up space
    return head;
}
int main()
{

    return 0;
}