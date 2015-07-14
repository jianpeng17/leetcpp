#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                ListNode* next = cur->next;
                removeNode(pre, cur, next);
                cur = next;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
    void removeNode(ListNode* pre, ListNode* cur, ListNode* next)
    {
        pre->next = next;
        delete cur; // jima1, no need to delete, you don't know if it is newed in heap
    }
};


int main()
{
    ListNode a1(1);
    ListNode b1(2);
    ListNode c1(3);
    ListNode d1(99);
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;

    Solution s;
    ListNode* result = s.removeElements(&a1, 1);
    while(result!=NULL)
    {
        cout<<result->val<<" ";
        result= result->next;
    }

    return 1;
}

