#include <bits/stdc++.h>
using namespace std;

/*** USER DEFIEIND DATA-TYPE ***/
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

/*** CONVERSION OF LL INTO ARRAY ***/
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

/****  TRAVERSING IN A LINKED LIST   ****/
void printy(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/*** REVERSING A LL ***/
Node *reverseLL(Node *head)
{

    Node *temp = head;
    // Node *prev = NULL;
    Node *previous = NULL;

    while (temp)
    {

        Node *dummy = temp->next; // storing it becuase temp->next would be manipulated further
        temp->next = previous;    // here it is manipulated
        previous = temp;
        temp = dummy;
    }

    return previous; // as previous would be pointing to the tail and thats the newHead after reversal so returning it;
}

// using iterarive approach LC
// ListNode *reverseList(ListNode *head)
// {

//     ListNode *prev = NULL;
//     ListNode *temp = head;

//     while (temp)
//     {
//         ListNode *storeNext = temp->next; // store the next address before manipulating
//         temp->next = prev;
//         prev = temp;

//         temp = storeNext;
//     }

//     return prev;
// }
// using recursive approach LC
//  void reverse(ListNode* head, ListNode*& prev) {

//         if (head == NULL)
//             return;

//         ListNode* storeNext;
//         storeNext = head->next;
//         head->next = prev;
//         prev = head;

//         reverse(storeNext, prev);
//     }

// public:
//     ListNode* reverseList(ListNode* head) {

//         ListNode* prev = NULL;
//         ListNode* temp = head;

//         reverse(temp, prev);

//         return prev;
//     }

// 19-5-2025
/*
     void reverse(ListNode* head, ListNode* prev,ListNode* &send) {

        if (head->next == NULL)
        {
            send=head; //as this is the last node
            head->next=prev;
            return;
        }

        reverse(head->next, head,send);
        head->next=prev;
    }

public:
    ListNode* reverseList(ListNode* head) {

        // //Recursive Approach
        // ListNode* prev= NULL; //to link the back
        // ListNode* send; //to store the last node as new head

        // if(head==NULL) return NULL;

        // reverse(head, prev,send);

        // return send;

        //Iterative Aproach
        ListNode* temp = head;
        ListNode* dummy = NULL;
        ListNode* prev= NULL;


        while(temp)
        {
            dummy=temp->next; //to store the next address
            temp->next=prev; //pointing to back
            if(dummy==NULL) break; //break as the temp would be pointing the last ndoe as newHead
            prev=temp; //update the prev for the next one as current
            temp=dummy; //moving the temp to next node
        }

        return temp;

    }
*/
int main()
{
    vector<int> v = {1, 2, 3, 5};
    Node *head = constructLL(v);

    head = reverseLL(head);
    printy(head);

    return 0;
}