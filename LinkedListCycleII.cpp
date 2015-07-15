#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        set<ListNode*> mySet;
        while(head)
        {
            cout<<"node val is "<<head->val<<endl;
            if( mySet.find(head) != mySet.end() )
            {
                return head;
            }
            else
            {
                mySet.insert(head);
                head = head->next;
            }
        }
        return NULL;
    }
};



int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &c;

    Solution s;
    ListNode* p = s.detectCycle(&a);
    cout<<"cycle begins at "<<p->val<<endl;

    return 1;
}

