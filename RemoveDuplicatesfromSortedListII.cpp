#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
       ListNode *cur=head,*pre=nullptr,*old=nullptr;
       while(cur)
       {
           old=cur->next;
           while(cur->next&&cur->val==cur->next->val)cur->next=cur->next->next;
           if(old!=cur->next)
           {
               if(pre)pre->next=cur->next;
               else head=cur->next;
           }
           else
           pre=cur;
           cur=cur->next;
       }
       return head;
    }
};

class Solution1 { // work for (1, 1, 2) and (1, 2, 2), don't work for (1,1,2,2)
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL) return NULL;

        ListNode dummy(0);
        ListNode* q = &dummy;

        ListNode* p = head;
        while(p != NULL)
        {

            if( p->next == NULL || (p->next != NULL && p->val != (p->next)->val) )
            {
                if(q != p)
                    q->next=p;
                q = q->next;
                p = p->next;
                continue;
            }

            while(p->next != NULL && p->val == (p->next)->val)
            {
                //ListNode* tmp = p->next;
                p->next = (p->next)->next;
                //delete tmp; // jima1, dont' need to delete if it is not newed
            }

            //ListNode* tmp = p;
            p = p->next;
            q->next=p;
            //delete tmp; // jima1, dont' need to delete if it is not newed
            q = q->next;

        }

        return dummy.next;
    }
};


class Solution2 {
public:
    ListNode *deleteDuplicates(ListNode *head) { // can not handle 1,1 case, which should remove all value in list
        if(head==NULL) return NULL;

        ListNode* p = head;
        while(p != NULL)
        {
            ListNode* nextNode = p->next;
            if(nextNode != NULL)
            {
                if(p->val==nextNode->val)
                {
                    ListNode* tmp = p->next;
                    p->next = tmp->next;
                    delete tmp;
                }
                else
                {
                    p = p->next;
                }
            }
            else
                return head;

        }
        return head;
    }
};



int main()
{
    ListNode a1(1);
    ListNode b1(1);
    ListNode c1(2);
    //ListNode d1(3);
    a1.next = &b1;
    b1.next = &c1;
    //c1.next = &d1;
    Solution s;
    ListNode * result = s.deleteDuplicates(&a1);
    while(result)
    {
        cout<<"val: "<<result->val<<endl;
        result = result->next;
    }

    return 1;
}

