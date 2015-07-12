#include <iostream>
#include <map> 
#include <vector>


/*
 Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 

*/



/*
My Note

不用判断slow节点的null，fast如果能走到后面，那slow也不会为NULL

todo: solve it without using extra space? 
*/



using namespace std;

class Solution {
public:
bool hasCycle(ListNode *head) {
// 设置两个指针，一个快一个慢
ListNode *slow = head, *fast = head;
while (fast && fast->next) {
slow = slow->next;
fast = fast->next->next;
if (slow == fast) return true;
}
return false;
}
};

int main()
{
    
    
    
    return 1;
}

