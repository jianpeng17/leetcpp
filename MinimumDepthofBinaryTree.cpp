#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>


/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/*
My Note 
要获得从根节点，到叶节点，最短路径
如果将获得数深度的函数改了，把max(left, right)换成min，就是错误的  //failed for case 1,2,3,4,#,#,5

左子树为空，就取右子树的深度
右子树为空，就取左子树的深度

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

class Solution1 { //failed for case 1,2,3,4,#,#,5
public:
    int minDepth(TreeNode *root) {
        if ( !root )
            return 0;
        
        int leftLen = getDepth(root->left)+1;
        int rightLen = getDepth(root->right)+1;
        if (rightLen == 1 && leftLen == 1)
            return 1;
        if (leftLen == 1) 
            return rightLen;
        if (rightLen == 1)
            return leftLen;

        return leftLen<rightLen ? leftLen : rightLen;
    }
    int getDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftLen = getDepth(root->left);
        int rightLen = getDepth(root->right);
        return (leftLen<rightLen ? leftLen : rightLen) + 1 ;
    }
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root==NULL) return 0;
        if (root->left == NULL) return minDepth(root->right)+1;
        if (root->right == NULL) return minDepth(root->left)+1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};

// jima1 todo, dfs to solve this


int main()
{
    
    Solution s;
    
    return 1;
}

