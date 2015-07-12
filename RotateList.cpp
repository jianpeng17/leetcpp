#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL)
            return NULL;
        if(k==0)  //bug here, should not be "k=0", k==0!!!
            return head;
        ListNode* p = head;
        int len=1;
        while( p->next != NULL )
        {
            len++;
            p=p->next;
        }
        p->next = head;
        int r = len-k%len;

        for(int i=0; i<r; i++)
        {
            p = p->next;
        }
        ListNode* result = p->next;
        p->next = NULL;
        return result;
    }
};


int main()
{
    ListNode a(1);
    ListNode b(2);
    a.next = &b;

    Solution s;
    ListNode* p = s.rotateRight(&a,1);
    while(p!=NULL)
    {
        cout<<"val of node is "<<p->val<<endl;
        p=p->next;
    }

    return 1;
}

