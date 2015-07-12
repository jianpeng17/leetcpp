#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here'
xample:

   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 

*/
/*
My Note
preOrder 先序，先根节点，后左节点，最后右节点
inOrder 中序，先左节点，后跟节点，最后右节点
注意要遍历右子树

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vec;
        if(!root)
            return vec;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while(!stk.empty() || p!=NULL)
        {
            while(p != NULL)
            {
                stk.push(p);
                p = p->left;
            }
            if(!stk.empty())
            {
                p=stk.top();  // stk.pop() return void
                vec.push_back(p->val);
                p=p->right;
                stk.pop();
            }
        }
        return vec;
    }
};



int main()
{
    
    Solution s;
    
    return 1;
}

