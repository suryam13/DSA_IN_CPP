#include <bits/stdc++.h>
using namespace std;
//git
// Method 1- takes O(2N) in push and O(1) in rest
// stack<int> st1;
// stack<int> st2;

// MyQueue() {}

// void push(int x)
// {
//     // put entire into stack 2
//     while (!st1.empty())
//     {
//         st2.push(st1.top());
//         st1.pop();
//     }

//     // put the new element in stack 1
//     st1.push(x);

//     while (!st2.empty())
//     {
//         st1.push(st2.top());
//         st2.pop();
//     }
// }

// int pop()
// {

//     int val = st1.top();
//     st1.pop();
//     return val;
// }

// int peek() { return st1.top(); }

// bool empty() { return st1.empty(); }

/*
Method 2 : Takes O(N) for pop() and for front() rest O(1)

    stack<int> st1;
    stack<int> st2;
    MyQueue() {}

    void push(int x) { st1.push(x); }

    int pop() {

        int val;

        if (!st2.empty()) {
            val = st2.top();
            st2.pop();
        }

        else {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            val = st2.top();
            st2.pop();
        }
        return val;
    }

    int peek() {

        int val;

        if (!st2.empty())
            val = st2.top();

        else {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            val = st2.top();
        }
        return val;
    }

    bool empty() { return (st2.empty() && st1.empty()); }
*/
int main()
{

    return 0;
}