#include <bits/stdc++.h>
using namespace std;
// SHEET LC-2

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // we use dummy node to make the headReturn easier
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    ListNode *list1 = l1;
    ListNode *list2 = l2;

    int carry = 0;
    int val1 = 0;
    int val2 = 0;

    while (list1 || list2 || carry)
    {
        if (list1)
            val1 = list1->val; // only if it is not NULL else would give error if we extract

        else
            val1 = 0;

        if (list2)
            val2 = list2->val;

        else
            val2 = 0;

        int ans = val1 + val2 + carry; // final ans
        carry = ans / 10;              // suppose 19 so 1 is carry that is to be transferred next
        ans = ans % 10;                // last unit place would be given

        ListNode *final = new ListNode(ans); // making the node

        temp->next = final; // pointing to final

        temp = temp->next; // temp goes to next(which is now NULL)

        if (list1)
            list1 = list1->next; // move only if valid else wouldd give error if we extract

        if (list2)
            list2 = list2->next;
    }
    return dummy->next; // dummy->next would be newHead
}
int main()
{

    return 0;
}