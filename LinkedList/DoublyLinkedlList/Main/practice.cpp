#include <bits/stdc++.h>
using namespace std;

/*** User Defined DataType Node ***/
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

public:
    Node(int data1) // constructor to initialize automatically with nullptr
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

/*** Converting an array into doubly linked list ***/
Node *convertArrToLL(vector<int> &v)
{
    Node *head = new Node(v[0]); // this is the head of the LL head->prev is nullptr by default;

    Node *mover = head; // mover is pointing to head and they have to point to same address as further it would be linked
    Node *dummy;

    for (int i = 1; i < v.size(); i++)
    {
        // Node *temp = new Node(v[i]);
        // mover->next = temp;
        // temp->prev=mover;
        // mover = temp; // or mover=mover->next as it has to move forward

        // OR can follow this

        Node *temp = new Node(v[i], nullptr, mover);
        // means now prev is pointing to mover means backside
        mover->next = temp;
        mover = temp;
    }
    return head;
}

/****  TRAVERSING IN A DOUBLY LINKED LIST   ****/
void printy(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/*** DELETION OF A HEAD OF A DOUBLY LINKED LIST ***/
Node *deleteHead(Node *head)
{
    if (head == nullptr) // means empty
        return head;

    if (head->next == nullptr) // means single node
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // means multiple nodes
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}

/*** DELETION OF A TAIL OF A DOUBLY LINKED LIST ***/
Node *deleteTail(Node *head)
{
    if (head == nullptr) // means empty
        return head;

    if (head->next == nullptr) // means single node
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // means multiple nodes
    Node *temp = head;
    Node *dummy;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // dummy->next = nullptr;
    dummy = temp->prev; // gives the second last node
    dummy->next = nullptr;
    temp->prev = nullptr;

    delete temp;
    // delete dummy;cannot delete dummy as it is pointing to some nodes whereas temp is pointing to nullptr in both next and prev
    return head;
}

/*** DELETION OF A Kth OF A DOUBLY LINKED LIST ***/
Node *deleteKthElement(Node *head, int k)
{
    if (head == nullptr) // means empty
        return head;

    if (k == 1) // means single node deletion
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // means multiple nodes
    int cnt = 0;
    Node *temp = head;

    while (temp)
    {

        cnt++;
        if (cnt == k)
        {
            if (temp->next == nullptr)
                return deleteTail(head); // means it is a tail

            Node *back = temp->prev;
            Node *front = temp->next;

            back->next = front;
            front->prev = back;

            // temp->prev = nullptr;
            // temp->next = nullptr;
            // delete temp;

            // delete temp;
            return head;
        }
        temp = temp->next;
    }
}

/*** DELETION OF A GIVEN NODE OF A DOUBLY LINKED LIST ***/
void deleteNode(Node *node)
{
    // note that the head wont be given to delete

    Node *back = node->prev;
    Node *front = node->next;

    back->next = front;
    front->prev = back;

    node->next = nullptr;
    node->prev = nullptr;

    delete node;
}

/*** INSERTION OF A GIVEN NODE BEFORE THE HEAD OF A DOUBLY LINKED LIST ***/
Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val);

    temp->next = head;
    head->prev = temp;

    return temp;
}
/*** INSERTION OF A GIVEN NODE BEFORE THE TAIL OF A DOUBLY LINKED LIST ***/
Node *insertBeforeTail(Node *head, int val)
{
    Node *temp = new Node(val);
    Node *dummy = head;

    while (dummy->next != NULL)
    {
        dummy = dummy->next;
    }

    temp->next = dummy;
    temp->prev = dummy->prev;
    temp->prev->next = temp;
    dummy->prev = temp;

    return head;
}
/**** REVERSING A DLL ****/
Node *reversee(Node *head)
{
    Node *temp = head;

    Node *newHead;

    while (temp)
    {
        Node *dummy = temp->next;
        temp->next = temp->prev;
        temp->prev = dummy;

        newHead = temp;
        temp = dummy;
    }
    return newHead;

    /** ANOTHER METHOD **/

    // while (temp)
    // {
    //     back = temp->prev;       // storing the previous pointer
    //     temp->prev = temp->next; // simple transfer
    //     temp->next = back;       // using it to transfer so that it becomes reverse

    //     temp = temp->prev;
    //     // now to go forward remeber prev is now next so to move ahead have to move temp to prev
    // }
    // return back->prev; // at last the temp would be pointing to the second last node now to point the last we have to go to prev as prev is the new next
}
int main()
{
    vector<int> v = {33, 13, 25, 30, 2, 20};
    Node *head = convertArrToLL(v);

    // head = deleteHead(head);
    // printy(head);
    // cout << head->next << " " << head->prev;

    // head = deleteTail(head);
    // printy(head);
    // cout << head->next << " " << head->prev;

    // head = deleteKthElement(head, 5);
    // printy(head);
    // cout << head->next << " " << head->prev;

    // deleteNode(head->next->next->next->next);
    // printy(head);

    // head = insertHead(head, 2);
    // printy(head);

    // head = insertBeforeTail(head, 19);
    // printy(head);

    head = reversee(head);
    printy(head);

    return 0;
}