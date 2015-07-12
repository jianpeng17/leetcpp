#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.

Notes:

    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).


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

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> tmpStk1;
        stack<int> tmpStk2;
        
        tmpStk1.push(x);
        
        while(!stk.empty())
        {
            tmpStk2.push(stk.top());
            stk.pop();
        }
        while(!tmpStk2.empty())
        {
            tmpStk1.push(tmpStk2.top());
            tmpStk2.pop();
        }
        
        stk = tmpStk1;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stk.pop();
    }

    // Get the front element.
    int peek(void) {
        return stk.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
    }

    stack<int> stk;
};



int main()
{

    //Solution s;

    return 1;
}

