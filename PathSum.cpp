#include <iostream>
#include <map>
#include <vector>


/*

 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

*/

/*
My Note
如果当前节点为空，返回false
左子树和右子树都为空，就是leaf，现在就判断减剩下的值是不是0

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
    bool hasPathSum(TreeNode *root, int sum) {
        if ( !root )
            return false;

        int sub = sum - root->val;
        if( !root->left && !root->right )
            return sub==0;


        return ( hasPathSum(root->left, sub) || hasPathSum(root->right, sub) );

    }
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node3.right = &node5;

    Solution s;
    int sum = 7;
    bool b = s.hasPathSum(&node1, sum);
    cout<<"the answer is " << b <<endl;

    return 1;
}

