#include<bits/stdc++.h>
using namespace std;

class Node
{   
    public:
    int data;
    Node* next; //for my user defined data type i want two attributes data and the next pointer which points to the next address,Nodeso 
    //what kind of ptr is next int or what it would again point to another user defined data type Node



    Node(int data,Node *next) //Node *ptr --> variable
    {
        this->data = data;
        this->next = next;

    }

    Node (int val)
    {
        this->data=val;
    }
};

 int main()
{   
    // Node *dummy ;

    //concept of double pointer
    // Node *head = new Node(5,&dummy);
    //   Node(int val,Node **ptr) //Node *ptr --> variable
    // {
    //     data = val;
    //     next = *ptr;

    // }

    // Node *head = new Node(5,dummy);
    
    // cout<<dummy<<endl; //prnts the garbage value which is stored inside the dummy
    // cout<<&dummy<<endl; //prints the actual address of the dummy on the stack


//    Node *dum = new Node(7,head);
//    Node* hey;
//    hey = dum;

//    cout<<dum->next<<endl;
//    cout<<hey->next<<endl;

//    hey->next=NULL;
//    delete hey;
//    cout<<dum->next<<endl;

    Node* head= new Node(7,nullptr);
    Node *dummy;
    dummy = head;
    head->data=5;
    cout<<dummy->data;


    // cout<<head->data<<" "<<head->next;
    return 0;
}