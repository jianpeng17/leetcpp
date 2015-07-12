#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*

Given preorder and inorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder.begin(), preorder.end(),
                        inorder.begin(), inorder.end());

        /*
        if(preorder.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(*preorder.begin());
        if(preorder.size() == 1) // only 1 number, then arguments to construct other vector may be invalid
            return root;
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), *preorder.begin());
        int offset = it - preorder.begin();
        vector<int> preLeft(preorder.begin()+1, preorder.begin()+offset+1);
        vector<int> inLeft(inorder.begin(), inorder.begin()+offset);
        vector<int> preRight(preorder.begin()+offset+1, preorder.end());
        vector<int> inRight(inorder.begin()+offset+1, inorder.end());
        root->left = buildTree( preLeft, inLeft );
        root->right = buildTree( preRight, inRight  );
        //root->left = buildTree( vector<int>(preorder.begin()+1, preorder.begin()+offset+1), vector<int>(inorder.begin(), inorder.begin()+offset) );
        //root->right = buildTree( vector<int>(preorder.begin()+offset+1, preorder.end()), vector<int>(inorder.begin()+offset+1, inorder.end())  );
        return root;
        */
    }

    template<typename Iterator>
    TreeNode* buildTree(Iterator pre_begin, Iterator pre_end, Iterator in_begin, Iterator in_end)
    {
        if(pre_begin == pre_end) return NULL;
        if(in_begin == in_end) return NULL;

        TreeNode* root = new TreeNode(*pre_begin);
        auto it = find(in_begin, in_end, *pre_begin);
        auto offset = distance(in_begin, it);

        root->left = buildTree(next(pre_begin), next(pre_begin, offset+1), in_begin, next(in_begin,offset));
        root->right = buildTree(next(pre_begin, offset+1), pre_end, next(in_begin, offset+1), in_end);
        return root;
    }
};



int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    vector<int> b;
    b.push_back(2);
    b.push_back(1);
    Solution s;
    TreeNode* node = s.buildTree(a, b);
    return 1;
}

