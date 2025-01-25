#include <bits/stdc++.h>
using namespace std;
// SHEET-GFG
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// MY METHOD
Node *segregate(Node *head)
{

    Node *newHead;
    bool check0 = 1;
    bool check1 = 1;
    bool check2 = 1;
    Node *zero = NULL;
    Node *one = NULL;
    Node *two = NULL;
    Node *startTwo = NULL;
    Node *startOne = NULL;
    Node *temp = head;

    while (temp)
    {
        if (temp->data == 0)
        {
            if (check0)
            {
                newHead = temp;
                zero = temp;
                check0 = 0;
            }
            else
            {
                zero->next = temp;
                zero = temp;
            }
        }

        else if (temp->data == 1)
        {
            if (check1)
            {
                one = temp;
                check1 = 0;
                startOne = temp;
            }

            else
            {
                one->next = temp;
                one = temp;
            }
        }
        else
        {
            if (check2)
            {
                two = temp;
                check2 = 0;
                startTwo = temp;
            }
            else
            {
                two->next = temp;
                two = temp;
            }
        }

        temp = temp->next;
    }

    if (zero == NULL && one == NULL)
        return startTwo;

    else if (zero == NULL && two == NULL)
        return startOne;

    else if (one == NULL && two == NULL)
        return newHead;

    else if (one == NULL)
    {
        zero->next = startTwo;
        two->next = NULL;
        return newHead;
    }

    else if (two == NULL)
    {
        zero->next = startOne;
        one->next = NULL;
        return newHead;
    }

    else if (zero == NULL)
    {
        one->next = startTwo;
        two->next = NULL;
        return startOne;
    }

    else
    {
        zero->next = startOne;
        one->next = startTwo;
        two->next = NULL;
    }

    return newHead;
}

// METHOD-2
Node *segregate(Node *head)
{

    Node *newHead;

    Node *startZero = new Node(-1);
    Node *startOne = new Node(-1);
    Node *startTwo = new Node(-1);

    Node *zero = startZero;
    Node *one = startOne;
    Node *two = startTwo;

    Node *temp = head;

    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }

        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }

        temp = temp->next;
    }

    zero->next = (startOne->next) ? (startOne->next) : (startTwo->next);
    one->next = (startTwo->next);
    two->next = NULL;

    newHead = startZero->next;
    return newHead;
}
int main()
{

    return 0;
}