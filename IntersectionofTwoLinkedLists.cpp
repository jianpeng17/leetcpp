#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>

/*

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

*/

/*
My Note
at which the intersection of two singly linked lists begins.
两个list开始相交，node只能指向一个node，所以不会分叉



*/


using namespace std;


struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        int lenA = getListLen(headA);
        int lenB = getListLen(headB);
        cout<<"lenA is "<<lenA<<", lenB is "<<lenB<<endl;
        ListNode* lList;
        ListNode* sList;
        int sLen;

        if (lenA > lenB)
        {
            lList = headA;
            sList = headB;
            sLen = lenB;
        }
        else
        {
            lList = headB;
            sList = headA;
            sLen = lenA;
        }
        int sub = abs(lenA-lenB);
        for(int i = 0; i<sub; i++)
        {
            lList = lList->next;
        }
        for(int i = 0; i< sLen; i++) // i must be 0, can't be 1, in case the last node is the intersection node
        {
            if(lList == sList)
            {
                return lList;
            }
            else
            {
                lList=lList->next;
                sList=sList->next;
            }
        }
        return NULL;

    }

    int getListLen(ListNode* node)
    {
        if(node == NULL)
            return 0;
        int len=1;

        while(node->next != NULL)
        {
            len++;
            node = node->next;
        }
        return len;

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


    return 1;
}

