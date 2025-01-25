#include <bits/stdc++.h>
using namespace std;

//LC-876
//* Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {

        // Tortoise and Hare Algorithm
        ListNode *slow = head; // at last slow would be pointing to mid
        ListNode *fast = head; // if nodes are in even count then it would go to
                               // NULL else would go to last Node

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;

        // The algorithm requires the 'fast' pointer to reach the end of the
        // list which it does after approximately N/2 iterations (where N is the
        // total number of nodes). Therefore, the maximum number of iterations
        // needed to find the middle node is proportional to the number of nodes
        // in the list, making the time complexity linear, or O(N/2) ~ O(N).
    }
};
int main()
{

    return 0;
}