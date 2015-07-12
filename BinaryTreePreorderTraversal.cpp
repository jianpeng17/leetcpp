#include <iostream>
#include <map>
#include <vector>
#include <stack>


/*
Given a binary tree, return the preorder traversal of its nodes�� values.
For example: Given binary tree {1,#,2,3},
1
\
2
/
return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?

*/

/*
My Note
preOrder �����ȸ��ڵ㣬����ڵ㣬����ҽڵ�
inOrder ��������ڵ㣬����ڵ㣬����ҽڵ�
ע��Ҫ����������

*/

using namespace std;


//Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// LeetCode, Binary Tree Preorder Traversal
// ʹ��ջ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
class Solution {
    public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vec;
        if (root == NULL)
            return vec;
        stack<TreeNode*> sta;
        TreeNode* p = root;
        //sta.push(p);
        while(p!= NULL || !sta.empty())  // should be ||
        {
            while(p)
            {
                vec.push_back(p->val);
                //p = p->left;
                sta.push(p);
                p = p->left;
            }

            p = sta.top();
            p = p->right;
            sta.pop();

        }
        return vec;
    }
};

int main()
{

    Solution s;

    return 1;
}

