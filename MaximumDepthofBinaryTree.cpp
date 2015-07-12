#include <iostream>
#include <map>
#include <vector>


/*

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        return max( maxDepth(root->left), maxDepth(root->right) ) +1;
        
    }
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(1);
    TreeNode node4(1);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    Solution s;
    
    int depth = s.maxDepth(&node1);
    cout<<"depth is "<<depth<<endl;
    return 1;
}

