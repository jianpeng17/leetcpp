#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        int leftLen = getHeight(root->left);
        int rightLen = getHeight(root->right);
        if ( abs(leftLen-rightLen) > 1 )
            return false;
        else
            return (isBalanced(root->left) && isBalanced(root->right)); // the balance tree definition is recursive

    }
    int getHeight(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int leftLen = getHeight(root->left);
        int rightLen = getHeight(root->right);
        return ( leftLen>rightLen ? leftLen : rightLen) + 1;

    }
};


int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;

    TreeNode node4(4);
    TreeNode node5(5);
    node2.left = &node4;
    node2.right = &node5;

    TreeNode node6(6);
    TreeNode node7(7);
    node3.left = &node6;
    node3.right = &node7;

    TreeNode node8(8);
    TreeNode node9(9);
    node4.left = &node8;
    node4.right = &node9;

    TreeNode node10(10);
    node5.left = &node10;

    Solution s;
    cout<<"balanced? "<<s.isBalanced(&node1)<<endl;

    return 1;
}

