#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

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

// non-recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==NULL || q == NULL)
            return p==NULL ? q : p;

        while(root)
        {
            if(root->val > p->val && root->val > q->val)
            {
                root = root->left;
                continue;
            }
            if(root->val < p->val && root->val < q->val)
            {
                root = root->right;
                continue;
            }
            if( (root->val == p->val || root->val == q->val) ||
                (root->val > p->val && root->val < q->val) ||
                (root->val < p->val && root->val > q->val))
                return root;
            else
                return NULL;
        }
        return NULL;
    }
};

//recursive
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int max = p->val > q->val ? p->val: q->val;
        int min = p->val < q->val ? p->val: q->val;

        if(root->val > max)
        {
            return lowestCommonAncestor(root -> left, p, q);
        }

        if(root->val < min)
        {
            return lowestCommonAncestor(root -> right, p, q);
        }

        return root;
    }
};


int main()
{

    Solution s;

    return 1;
}

