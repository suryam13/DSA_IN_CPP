// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     /*** Pointer Logic ***/
//     // int a=2;
//     // int *b=&a;

//     // cout<<b<<endl;//address
//     // cout<<*b;//value

//     int a = 2;
//     int *b = &a;
//     int *c = &(*b);

//     cout << a << " " << *b << *c;
//

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Node // Node is name of userdefined datatype just like int and float but the working is different and struct is the keyword to define userdefined datatype
{
public: // means this struct values are accessible outside the struct
    int value;
    Node *next; // just like int *a it would be storing the address of next

public: // public makes this constructor accessible outside the struct
    // this is the constructor used to intialize members of the struct above using new values when called
    Node(int value1, Node *next1)
    {
        value = value1;
        next = next1;
    }
};

/*** Converting an array into linked list ***/
Node *convertArrToLL(vector<int> &v)
{
    Node *head = new Node(v[0], nullptr); // this is the head of the LL
    Node *mover = head;                   // mover is pointing to head and they ghave to point to same address as further it would be linked

    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i], nullptr);
        mover->next = temp;
        mover = temp; // or mover=mover->next as it has to move forward
    }
    return head;
}

/*** SEARCH IN A LL***/
int checkPresent(Node *head, int val)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->value == val)
            return 1;

        temp = temp->next;
    }

    return 0;
}

/****  TRAVERSING IN A LINKED LIST   ****/
void printy(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

/*** Deletion of head of LL ***/
Node *deletee(Node *head)
{
    // if(head==nullptr) return head; //both are same means the head itself is a nullptr
    if (head == NULL)
        return head;

    Node *temp = head;
    // for deleting the temp afterwards

    head = head->next;

    delete temp;
    // free (temp); //either this can be used

    return head;
}

/*** Deletion of tail of LL ***/

Node *tail(Node *head)
{
    if (head == NULL || head->next == NULL) // means either it is empty or single element
        return NULL;

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // freeeing up the space by last node
    delete temp->next;
    temp->next = NULL;

    return head;
}

/*** Deletion of a ith element of LL ***/

Node *deleteNode(Node *head, int pos)
{
    // have to return head

    if (head == NULL)
        return head; // means no element

    if (pos == 1) // means has to delete head
    {
        Node *temp = head;

        head = head->next;
        free(temp);
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    int cnt = 0;

    while (temp)
    {

        cnt++;

        if (cnt == pos)
        {
            prev->next = prev->next->next; // prev->next=temp->next
            delete temp;
            return head;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}

/*** Deletion of a given element in LL ***/

Node *deleteElement(Node *head, int val)
{
    // have to return head

    if (head == NULL)
        return head; // means no element

    if (head->value == val) // means has to delete head
    {
        Node *temp = head;

        head = head->next;
        free(temp);
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp)
    {

        if (temp->value == val)
        {
            prev->next = prev->next->next; // prev->next=temp->next
            delete temp;
            return head;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}

/*** INSERTION AT HEAD IN LL ***/
Node *addtoHead(Node *head, int val)
{
    // have to return head
    Node *dummy = new Node(val, head);
    return dummy;
}

/*** INSERTION AT TAIL IN LL ***/
Node *addtoTail(Node *head, int val)
{
    // have to return head
    Node *dummy = new Node(val, nullptr);
    if (head == NULL)
        return dummy;

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = dummy;

    return head;
}

/*** INSERTION AT K POSITION (1 MEANS HEAD POSITION) ***/
Node *addKPos(Node *head, int val, int pos)
{
    int cnt = 0;
    Node *dummy = new Node(val, nullptr);
    Node *temp = head;

    if (head == NULL)
    {
        if (pos == 1)
            return dummy;
        else
            return NULL;
    }

    if (pos == 1)
    {
        dummy->next = head;
        return dummy;
    }

    while (temp)
    {
        cnt++;

        if (cnt == pos - 1)
        {
            dummy->next = temp->next;
            temp->next = dummy;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> v = {111, 852, 255, 494, 85, 8854};

    // // preferred method
    // Node *y=new Node(v[0],nullptr);//this directly points to the address

    // cout<<y<<endl;//gives address
    // cout<<y->next<<endl; //gives the next
    // cout<<y->value<<endl; //gives the value

    // Alternate method
    //  Node x=Node(v[0],nullptr);//this simply creates an object,no address
    //  //if want pointer to this
    //  Node *y=&x;
    //  cout<<x.next<<endl;
    //  cout<<x.value<<endl;
    //  cout<<y->value<<endl;
    //  cout<<y->next<<endl;

    /*** Converting an array into linked list ***/
    Node *head = convertArrToLL(v);
    // cout << head->value;

    /****  TRAVERSING IN A LINKED LIST   ****/
    // printy(head);

    /*** FINDING LENGTH OG L.L ***/
    // cout << len << endl;

    /*** SEARCH IN A LL***/
    // cout << checkPresent(head, 275);
    // cout << head;

    /*** Deletion of head of LL ***/
    // head = deletee(head);
    // printy(head);

    /*** Deletion of tail of LL ***/
    // head = tail(head);
    // printy(head);

    /*** Deletion of a ith element of LL ***/
    // head = deleteNode(head, 3);
    // printy(head);

    // /*** Inserting at head position ***/
    // head = addtoHead(head, 3);
    // printy(head);

    /*** Inserting at head position ***/
    // head = addtoTail(head, 3);
    // printy(head);

    /*** Inserting at specified position ***/
    // head = addKPos(head, 420, 1);
    // printy(head);

    return 0;
}