#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*
 Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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

class Solution1 {  //failed for case 10,5,15,#,#,6,20
// failed if INT_MAX is the root
public:
    bool isValidBST(TreeNode *root) {
        return validateBST(root, INT_MIN, INT_MAX);
    }

    bool validateBST(TreeNode *root, int low, int high)
    {
        if(root == nullptr) return true;
        return ( (root->val > low) && (root->val < high)
                && validateBST(root->left, low, root->val)
                && validateBST(root->right, root->val, high));
    }
};


class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return validateBST(root, nullptr, nullptr);
    }

    bool validateBST(TreeNode *root, int* low, int* high)
    {
        if(root == nullptr) return true;

        if( (low!=nullptr && root->val <=*low) || (high!=nullptr && root->val >= *high))
            return false;
        return  validateBST(root->left, low, &(root->val))
                && validateBST(root->right, &(root->val), high);
    }
};

int main()
{

    Solution s;

    return 1;
}

