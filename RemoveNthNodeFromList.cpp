#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

remove the Nth number from list

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

ListNode* removeN(ListNode* header, int n)
{
    if (header == NULL )
        return NULL;
    if (n<1)
        return header;
    ListNode* p = header;
    ListNode* pre = p;
    if ( n==1  )
    {
        header = header->next;
        delete p;
        return header;
    }
    for(int i=1; i<n && p!=NULL; i++)
    {
        pre=p;
        p=p->next;
    }
    if(p==NULL)
    {
        pre->next = NULL;
        delete p;
    }
    else
    {
        pre->next = p->next;
        delete p;
    }
    return header;
}



int main()
{
    ListNode a1(1);
    ListNode b1(2);
    ListNode c1(3);
    a1.next = &b1;
    b1.next = &c1;

    int i = 3;
    ListNode* result = removeN(&a1, i);
    while(result!=NULL)
    {
        cout<<"current val is " << result->val<<endl;
        result = result->next;
    }

    return 1;
}

