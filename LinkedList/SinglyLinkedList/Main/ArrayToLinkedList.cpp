#include <bits/stdc++.h>
using namespace std;
// Sheet-GFG
class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *constructLL(vector<int> &arr)
    {

        Node *head = new Node(arr[0]); // head will be the first element in the array
        Node *mover = head;            // used to attach the next

        // now linking the remaining
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }

        return head;
    }
};
int main()
{

    return 0;
}