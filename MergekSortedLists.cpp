#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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


class Solution1 { // this solution will exceed time limit
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return NULL;
        ListNode* p=*(lists.begin());
        for(vector<ListNode *>::iterator it = lists.begin()+1; it != lists.end(); it++)
        {
            p = mergeTwoSortedList(p, *it);
        }
        return p;

    }
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode dummy(0);
        ListNode* p = &dummy;
        for( ; l1!=NULL && l2!=NULL; p=p->next)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1=l1->next;
            }
            else
            {
                p->next = l2;
                l2=l2->next;
            }
        }
        p->next = (l1!=NULL) ? l1 : l2;
        return dummy.next;
    }

};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return NULL;
        ListNode dummy(INT_MIN);
        ListNode* result = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, comparator> q;
        //cout<<"debug 1"<<endl;
        for(vector<ListNode *>::iterator it = lists.begin(); it!=lists.end(); it++)
        {
            if(*it != NULL)// jima1, to prevent ListNode is NULL
                q.push(*it);
        }
        //cout<<"debug 2"<<endl;
        while(!q.empty())
        {
            //cout<<"debug 3"<<endl;
            ListNode* current = q.top();
            //cout<<"current val is "<<current->val<<endl;
            result->next = current;
            if( current->next != NULL )
                q.push( current->next );
            q.pop();
            result = result->next;
        }
        return dummy.next;

    }
    struct comparator
    {
        bool operator() (const ListNode* l1, const ListNode* l2)
        {
            return l1->val > l2->val; // jima1, notice the operator >, if the order is ascending order
        }
    };

};

int main()
{
    ListNode a1(1);
    ListNode b1(2);
    ListNode a2(3);
    ListNode b2(4);
    ListNode c2(5);
    a1.next = &b1;
    a2.next = &b2;
    b2.next = &c2;
    vector<ListNode*> vec;
    vec.push_back(&a1);
    vec.push_back(&a2);
    Solution s;
    ListNode* result = s.mergeKLists(vec);
    while(result != NULL)
    {
        cout<<"val in result is "<<result->val<<endl;
        result = result->next;
    }
    vector<ListNode*> vec2;
    ListNode* a3 = NULL;
    vec2.push_back(a3);
    ListNode* result2 = s.mergeKLists(vec2);
    while(result2 != NULL)
    {
        cout<<"val in result is "<<result2->val<<endl;
        result2 = result2->next;
    }
    return 1;
}

