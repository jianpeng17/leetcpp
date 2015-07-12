#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.

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


class Solution1 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {  // special case handle for ({1,2}, 1) ({1,2}, 2) ({1},1)
        if(n==0)
            return head;
        ListNode* p=head;
        ListNode* q=head;
        ListNode* pre=q;
        int step = n-1;
        while(step>0 && p->next!=NULL)
        {
            p=p->next;
            step--;
        }
        if(p->next==NULL && step>0)
            return head;
        while(p->next!=NULL)
        {
            pre=q;
            q=q->next;
            p=p->next;
        }
        /*
        if(pre == head)
        {
            head=head->next;
            delete pre; // not delete head will cause leak
            return head;
        }
        */

            if(pre == head && q->next!=NULL)
            {
                head=head->next;
                delete pre; // not delete head will cause leak
                return head;
            }

            pre->next = q->next;
            delete q;

        return head;
    }
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* p = &dummy;
        ListNode* q = &dummy;
        for(int i=0; i<n; i++)
            p=p->next;
        while(p->next != NULL)
        {
            q=q->next;
            p=p->next;
        }
        ListNode* tmp = q->next; // delete q's next
        q->next = tmp->next;
        delete tmp;
        return dummy.next;
    }
};



int main()
{
    ListNode a1(1);
    ListNode b1(2);
    ListNode c1(3);
    a1.next = &b1;
    b1.next = &c1;

    Solution s;
    int i = 2;
    ListNode* result = s.removeNthFromEnd(&a1, i);
    while(result!=NULL)
    {
        cout<<"current val is " << result->val<<endl;
        result = result->next;
    }
    return 1;
}

