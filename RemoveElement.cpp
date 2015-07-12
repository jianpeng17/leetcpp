#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. 

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
    int removeElement(int A[], int n, int elem) {
        int j=0;
        for(int i=0; i<n; i++)
        {
            if(A[i] != elem)
                A[j++] = A[i];
        }
        return j;
    }
};


int main()
{
    
    Solution s;
    
    return 1;
}

