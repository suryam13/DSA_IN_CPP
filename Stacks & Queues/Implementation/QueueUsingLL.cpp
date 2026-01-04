#include <bits/stdc++.h>
using namespace std;

/*
//initially front and rear are pointing to NULL
//rear-->head
//front-->tail
void MyQueue:: push(int x)
{   
    
   QueueNode* ele=new QueueNode(x);
   
   if(rear==NULL) //means first node is to be added now!
   {rear=ele;
    front=ele;
    //now both are pointing to first element
   }
   
   else 
  { //means more than one element 
     front->next=ele; //pointing to the newly made node
     front=front->next; //moving to newly added node
   }
   
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{   
    if(rear==NULL)
    return -1;  //no nodes
    
    
    int toRet=rear->data;
    
    QueueNode* toDel=rear;
    rear=rear->next; 
    

    delete toDel; //to make memory efficient

    return toRet;
}
*/
int main()
{

    return 0;
}