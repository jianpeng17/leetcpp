#include <iostream>
#include <map>
#include <vector>


/*

 Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.



*/

/*
My Note
左子树和右子树都为空，返回true
只有一个是空，就不是same tree
再判断值相等，左子树相同，右子树相同

*/


using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if( !p && !q ) return true;
        if( !p || !q ) return false;
        return ( p->val == q->val 
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right) )
        
    }
};

int main()
{

    Solution s;

    return 1;
}

