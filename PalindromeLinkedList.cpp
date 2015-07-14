#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

*/

using namespace std;


struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        stack<int> stk;
        ListNode* oneStep = head, *twoStep = head;
        while(twoStep->next && twoStep->next->next)
        {
            stk.push(oneStep->val);
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }
        if(twoStep->next && !twoStep->next->next)
            stk.push(oneStep->val);
        ListNode* cur = oneStep->next;
        while(cur)
        {
            if(stk.top() != cur->val)
                return false;
            stk.pop();
            cur = cur->next;
        }
        return true;
    }
};


int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(2);
    //ListNode d(3);
    ListNode e(1);
    a.next = &b;
    b.next = &c;
    c.next = &e;
    //d.next = &e;
    Solution s;
    assert(s.isPalindrome(&a));

    return 1;
}

