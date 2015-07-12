#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_set>

/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 ¡ú a2
                   ¨K
                     c1 ¡ú c2 ¡ú c3
                   ¨J
B:     b1 ¡ú b2 ¡ú b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA ==NULL || headB==NULL)
            return NULL;
        unordered_set<ListNode*> nodeSet;
        while(headA != NULL)
        {
            nodeSet.insert(headA);
            headA = headA->next;
        }
        while(headB != NULL)
        {
            if (nodeSet.find(headB) != nodeSet.end() )
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};



int main()
{

    ListNode a1(1);
    ListNode a2(4);
    ListNode b1(2);
    ListNode b2(5);
    ListNode c1(3);
    ListNode d(99);
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d;

    a2.next = &b2;
    b2.next = &d;
    Solution s;
    ListNode* inter = s.getIntersectionNode(&a1, &a2);
    cout<<"intersection node with value "<< inter->val<<endl;
}

