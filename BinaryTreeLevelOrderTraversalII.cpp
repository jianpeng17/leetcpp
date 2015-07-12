#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]


*/

/*
My Note
reverse一下binaryTreeLevelOrderTraversal的结果

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> vv;
        if(root==NULL)
            return vv;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> v;
            vector<TreeNode*> levelVec;
            while(!q.empty())
            {
                TreeNode* p = q.front();// jima1 front() access the first element
                levelVec.push_back(p);
                v.push_back(p->val);
                q.pop();
            }
            vv.push_back(v);
            for(vector<TreeNode*>::iterator it = levelVec.begin(); it!=levelVec.end(); it++)
            {
                if((*it)->left != NULL) // jima1 need to check NULL before insert to queue
                    q.push((*it)->left);
                if((*it)->right != NULL)
                    q.push((*it)->right);
            }
        }
        reverse(vv.begin(), vv.end());
        return vv;
    }
};



int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    Solution s;

    return 1;
}

