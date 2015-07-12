#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
  Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
 */
struct ListNode
{
    ListNode(int dataIn):
        val(dataIn),
        next(NULL) // next is a pointer, need to set
    {}
    int val;
    ListNode* next;
};

// do we need to destruct node when the node is not linked
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode* node = head;
        while(node->next != NULL)
        {
            if( node->val == (node->next)->val )
            {
                if ( ((node->next)->next) != NULL )
                {
                    ListNode* p = (node->next)->next;
                    delete node->next;
                    node->next = p;
                    //node = p; // no need to jump, because there may be over 3 same values in the list
                }
                else
                {
                    delete node->next;
                    node->next = NULL;  // also need to point to NULL
                }
            }
            else
                node = node->next;

        }
        return head;
    }
};

递归版
// LeetCode, Remove Duplicates from Sorted List
// 递归版，时间复杂度O(n)，空间复杂度O(1)
class Solution {
    public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        ListNode dummy(head->val + 1); // 值只要跟head 不同即可
        dummy.next = head;
        recur(&dummy, head);
        return dummy.next;
    }
    private:
    static void recur(ListNode *prev, ListNode *cur) {
        if (cur == nullptr) return;
        if (prev->val == cur->val) { // 删除head
            prev->next = cur->next;
            delete cur;
            recur(prev, prev->next);
        } else {
            recur(prev->next, cur->next);
        }
    }
};


迭代版
// LeetCode, Remove Duplicates from Sorted List
// 迭代版，时间复杂度O(n)，空间复杂度O(1)
class Solution {
    public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return nullptr;

        for (ListNode *prev = head, *cur = head->next; cur; cur = cur->next) {
            if (prev->val == cur->val) {
                prev->next = cur->next;
                delete cur;
            } else {
                prev = cur;
            }
        }
        return head;
    }
};


class LinkedList
{
    public:
        LinkedList()
        {
            header = NULL;
        }
        void insert(ListNode& nodeIn) //pass reference
        {
            if ( header == NULL)  // if header is null, set header first
            {
                header = &nodeIn;
                return;
            }

            ListNode* node = header;

            while(node->next != NULL)
            {
                node = node->next;
            }
            node->next = &nodeIn;
        }
        friend ostream& operator <<(ostream& os, const LinkedList& listIn);
    //private:
        ListNode *header;
        int size;
};
ostream& operator <<(ostream& os, const LinkedList& listIn)
{
    ListNode* node = listIn.header;
    while(node != NULL)
    {
        os <<" !: " << node->val <<endl;
        node = node->next;
    }
    return os;  // need return
}

int main()
{
    LinkedList list;
    ListNode node1(10);
    ListNode node2(20);
    ListNode node3(30);
    ListNode node4(30);
    ListNode node5(40);
    ListNode node6(40);
    ListNode node7(40);
    list.insert(node1);
    list.insert(node2);
    list.insert(node3);
    list.insert(node4);
    list.insert(node5);
    list.insert(node6);
    list.insert(node7);
    cout<<"list is "<<endl<< list <<endl;
    Solution s;
    ListNode* head = s.deleteDuplicates(list.header);
    cout<<"list is " <<endl <<list <<endl;
}
