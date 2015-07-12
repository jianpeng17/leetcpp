#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.

Notes:

    You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
    Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
    You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and all test cases.



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

// wrong, implement a queue using two queues
class Stack1 {
public:
    // Push element x onto stack.
    void push(int x) {
        mQ.push(x);
        if(pQ.empty())
        {
            pQ.push(mQ.front());
            mQ.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(pQ.empty())
            return;
        if(!mQ.empty())
        {
            pQ.push(mQ.front());
            mQ.pop();
        }
        pQ.pop();
        return;
    }

    // Get the top element.
    int top() {
        if(!pQ.empty())
            return pQ.front();
        return 0;
    }

    // Return whether the stack is empty.
    bool empty() {
        return pQ.empty();
    }

    queue<int> mQ; // mainQueue;
    queue<int> pQ; // popQueue

};

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue<int> tmpQ;
        tmpQ.push(x);
        while(!mQ.empty())
        {
            tmpQ.push(mQ.front());
            mQ.pop();
        }
        mQ = tmpQ;
    }

    // Removes the element on top of the stack.
    void pop() {
        mQ.pop();
    }

    // Get the top element.
    int top() {
        return mQ.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return mQ.empty();
    }

    queue<int> mQ; // mainQueue;

};


int main()
{

    Stack s;

    return 1;
}

