#include <bits/stdc++.h>
using namespace std;

//Binary Tree Template 
class Node
{
public:
    int data;
    Node *right;
    Node *left;

    // constructor function
    Node(int temp)
    {
        data = temp;
        right = nullptr;
        left = nullptr;
    }
};

int main()
{
    Node *root = new Node(7);   // the root is been created
    Node *child1 = new Node(8); // right child
    Node *child2 = new Node(6); // left child

    root->right = child1;
    root->left = child2;

    cout << root->right->data << '\n';
    cout << root->left->data;

    return 0;
}