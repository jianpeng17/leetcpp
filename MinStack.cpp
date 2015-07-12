#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.


*/

using namespace std;


struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class MinStack1 { // not constant time
    stack<int> myStack;
    vector<int> vec;
public:
    void push(int x) {
        myStack.push(x);
        vec.push_back(x);
        sort(vec.begin(), vec.end());
    }

    void pop() {
        int i = top();
        myStack.pop();
        vector<int>::iterator itor = find(vec.begin(), vec.end(), i);
        vec.erase(itor);
    }

    int top() {
        return myStack.top();
    }

    int getMin() {
        return *vec.begin();
    }
};

class MinStack {
    stack<int> myStack;
    stack<int> minStack;
public:
    void push(int x) {
        myStack.push(x);
        if(minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    void pop() {
        int i = top();
        myStack.pop();
        if(i == minStack.top())
            minStack.pop();
    }

    int top() {
        return myStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};


int main()
{


    return 1;
}

