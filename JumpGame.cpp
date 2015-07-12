#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false. 

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
    bool canJump(int A[], int n) {
        if (n==0 || n==1) // n==1
            return true;
        int step =A[0];
        if (step==0)
            return false;
        
        for(int i=1; i<n; i++)
        {
            if(i==n-1)
                return true;
            step = (A[i] > --step) ? A[i] : step;
            if (step == 0)
                return false;
        }
    }
};



int main()
{
    
    Solution s;
    
    return 1;
}

