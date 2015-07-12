#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Reverse a singly linked list.

click to show more hints.
Hint:

A linked list can be reversed either iteratively or recursively. Could you implement both?


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


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head, *pre = NULL, *q;
        while(cur != NULL)
        {
            q = cur->next;
            cur->next = pre;
            pre = cur;
            cur = q;
        }
        return pre;  // jima1, should return pre, not q
        
    }
};


int main()
{
    
    Solution s;
    
    return 1;
}

