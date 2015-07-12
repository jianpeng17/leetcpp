#include <iostream>
#include <map>
#include <vector>
#include <stack>


/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively. 


*/

using namespace std;


struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if( !root )
            return true;  // should not return false
        stack<TreeNode*> nodeStack;
        nodeStack.push(root->left);
        nodeStack.push(root->right);
        
        while(!nodeStack.empty())
        {
            TreeNode* left = nodeStack.top();
            nodeStack.pop();
            TreeNode* right = nodeStack.top();
            nodeStack.pop();
            
            if(!left && !right)
                continue;
            if(!left || !right)
                return false;
            if(left->val != right->val)
                return false;
            
            nodeStack.push(left->left);
            nodeStack.push(right->right);
            nodeStack.push(left->right);
            nodeStack.push(right->left);
        }
        
        return true;
        
    }
};

int main()
{

    Solution s;

    return 1;
}

