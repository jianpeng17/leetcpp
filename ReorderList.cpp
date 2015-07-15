#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
    void reorderList(ListNode *head) {
        if(head==NULL)
            return;
        vector<ListNode*> vec;
        while(head != NULL)
        {
            vec.push_back(head);
            head = head->next;
        }
        vector<ListNode*>::iterator itor1 = vec.begin();
        vector<ListNode*>::iterator itor2 = vec.end()-1;
        while(itor1 < itor2)
        {
            ListNode* node1 = *itor1;
            ListNode* node2 = *itor2;
            ListNode* tmp = node1->next;
            node1->next = node2;
            if(node2 != tmp)
                node2->next = tmp;
            else
                node2->next = NULL;  // jima1, pay attention to cycle link
            itor1++;
            itor2--;
        }
        if(itor1 == itor2)
            (*itor1)->next = NULL; // add null for the last node
    }
};


int main()
{
    ListNode a1(1);
    ListNode b1(2);
    ListNode c1(3);
    ListNode d1(4);
    ListNode e1(5);
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;
    d1.next = &e1;
    Solution s;
    s.reorderList(&a1);
    ListNode* node = &a1;
    while(node!=NULL)
    {
        cout<<node->val<<" ";
        node = node->next;
    }
    return 1;
}

