#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>


/*

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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


class Solution1 {  // this solution is inconsistent with title, 123+123 -> 246, but should return 642
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==NULL & l2==NULL)
            return NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        int num1 = getNUM(l1);
        int num2 = getNUM(l2);
        int sum = num1 + num2;
        cout<<"sum is "<<sum<<endl;
        ListNode* header=NULL;

        if(sum==0) // if both list are pointer to 0, this function will return null
        {
            header = new ListNode(0);
            return header;
        }

        while(sum)
        {
            int value = sum%10;
            ListNode* newNode = new ListNode(value);
            newNode->next = header;;
            header = newNode;
            sum = sum/10;
        }
        return header;

    }
    int getNUM(ListNode *node)
    {
        if(!node)
            return 0;
        int number = 0;
        while(node)
        {
            number = number*10+node->val;
            node = node->next;
        }
        return number;
    }
};

// jima1, 1234  123  return 2464, 1234 actually is 4321
// 7  &  7  return 41
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode* pre = &dummy;
        int carry=0;
        for( ; l1!=nullptr || l2!=nullptr;
        l1 = (( l1 != nullptr) ? l1->next : nullptr),// jima1, if no next, null
        l2 = (( l2 != nullptr) ? l2->next : nullptr),
        pre=pre->next )  // jima1, needed
        {
            int i1 = l1==nullptr ? 0 : l1->val;//jima1, if null, return 0 then
            int i2 = l2==nullptr ? 0 : l2->val;
            int value = (i1+i2+carry)%10; // notice it's %
            carry = (i1+i2+carry)/10;
            pre->next = new ListNode(value);
        }
        if(carry!=0)
            pre->next = new ListNode(carry);
        return dummy.next;
    }

};

int main()
{

    Solution s;
    ListNode node1(7);
    ListNode node2(5);
    ListNode* sum = s.addTwoNumbers(&node1, &node2);
    while(sum != nullptr)
    {
        cout<<"current val is "<< sum->val<<endl;
        sum = sum->next;
    }

    return 1;
}

