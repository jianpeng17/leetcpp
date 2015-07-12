#include <iostream>
#include <map>
#include <vector>


/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/

/*
My Note
compare and insert when both pointers are not null

also, if any node list has left pointers, insert to the last 

*/


using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 ==NULL && l2 ==NULL)
            return NULL;

        ListNode* dummy = new ListNode(0);;
        ListNode* node = dummy;

        ListNode* p = l1;
        ListNode* q = l2;
        while(p != NULL && q != NULL)
        {
            if ( p && q && p->val <= q->val )
            {
                node->next = p;
                p = p->next;
                node = node->next;
            }
            if ( p && q && q->val <= p->val )
            {
                node->next = q;
                q = q->next;
                node = node->next;
            }
        }

        if( p != NULL )
            node->next = p;
        if( q != NULL )
            node->next = q;

        return dummy->next;

    }
};

int main()
{

    Solution s;

    return 1;
}

