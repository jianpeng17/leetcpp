#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

 Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
*/

using namespace std;


struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* p1 = NULL;
        ListNode* cur = head;
        for(int i=1; i<m; i++)
        {
            p1 = cur;
            cur = cur->next;
        }

        ListNode* first = cur;
        ListNode* ccur = first;
        ListNode* p=NULL, *q=NULL;
        for(int i=m; i<=n; i++)
        {
            q = ccur->next;
            ccur->next = p;
            p = ccur;
            ccur = q;
        }
        if(p1) // jima1, if m==1, p1 is null;
            p1->next = p;
        if(q != NULL)
            first->next = q;

        if(m>1)
            return head;
        else
            return p;
    }

};




int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution s;
    ListNode* result = s.reverseBetween(&a, 2, 4);

    while(result!=NULL)
    {
        cout<<result->val<<" ";
        result = result->next;
    }

    return 1;
}

