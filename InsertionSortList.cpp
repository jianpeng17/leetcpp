#include <iostream>
#include <map>
#include <vector>


/*

Sort a linked list using insertion sort.
*/

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// my solution, new all node in the new list
class Solution1 {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode* dummy = new ListNode(0); // should choose the minimum value of int
        dummy->next = new ListNode(head->val); // cannot assign head to dummy->next, or it's circle
        ListNode* index = head->next;  // -> next is needed, or there will be two 1 nodes
        while(index)  // no need to index == NULL
        {
            cout<<"insert " << index->val <<" into list!"<<endl;
            insertToList(dummy, index->val);
            index = index->next;
            //cout<<"next node val is "<<index->val<<", node next is " << index->next<<endl;  //for last node null, it will dump
        }
        //cout<<"now insert the last node value into new list"<<endl;
        //insertToList(dummy, head->val);
        return dummy->next;
    }

    void insertToList(ListNode* dummy, int n)
    {
        ListNode* head = dummy->next;
        ListNode* newNode = new ListNode(n);
        if (head->val > n)
        {
            newNode->next = head;
            dummy->next = newNode;
            return;
        }
        while (head->next)
        {
            if( (head->next)->val > n) // find the first bigger value
            {
                newNode->next = head->next;
                head->next = newNode;
                return;
            }
            head = head->next;
        }
        head->next = newNode;
    }
};

class Solution {
public:
ListNode *insertionSortList(ListNode *head) {
    ListNode dummy(INT_MIN);
    cout<<"int_min is " << dummy.val<<endl;
    //dummy.next = head;
    for (ListNode *cur = head; cur != nullptr;)
    {
        auto pos = findInsertPos(&dummy, cur->val);
        ListNode *tmp = cur->next;  // tmp pointer, to be used in next iteration
        cur->next = pos->next;
        pos->next = cur;
        cur = tmp;
    }
    return dummy.next;
}

ListNode* findInsertPos(ListNode *head, int x) {
    ListNode *pre = nullptr;
    for (ListNode *cur = head; cur != nullptr && cur->val <= x;
        pre = cur, cur = cur->next)  // pre pointer, to be returned
    ;
    return pre;
}
};

int main()
{
    ListNode node1(41);
    ListNode node2(22);
    ListNode node3(14);
    ListNode node4(3);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    Solution s;
    ListNode* node5 = s.insertionSortList(&node1);
    ListNode* head = node5;
    while(head)
    {
        cout<<"current val is "<< head->val <<endl;
        head= head->next;
    }

    return 1;
}

