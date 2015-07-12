#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder.begin(), inorder.end(), 
                        postorder.begin(), postorder.end());
        
    }
    template<typename Iterator>
    TreeNode *buildTree(Iterator in_begin, Iterator in_end, Iterator post_begin, Iterator post_end )
    {
        if(in_begin == in_end) return NULL;
        if(post_begin == post_end) return NULL;
        TreeNode* root = new TreeNode(*(post_end-1));
        auto it = find(in_begin, in_end, *(post_end-1));
        auto offset = distance(in_begin, it);
        
        root->left = buildTree(in_begin, next(in_begin, offset), post_begin, next(post_begin, offset));
        root->right = buildTree(next(in_begin, offset+1), in_end, next(post_begin, offset), next(post_end, -1));
        return root;
    }    
};

struct TreeNode *buildTree(int *inorder, int *postorder, int n) {
    
    
}


int main()
{
    
    Solution s;
    
    return 1;
}

