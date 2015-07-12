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

�����ж�slow�ڵ��null��fast������ߵ����棬��slowҲ����ΪNULL

todo: solve it without using extra space? 
*/



using namespace std;

class Solution {
public:
bool hasCycle(ListNode *head) {
// ��������ָ�룬һ����һ����
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

