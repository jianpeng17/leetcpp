#include <iostream>
#include <map>
#include <vector>


/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

*/
/*
My Note
vector的构造，用a[10]来构造vector，是vector(a, a+10)? yes [first,last)
如果array size是1，取的就是arr[0]，没问题
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode( num[num.size()/2] );
        vector<int> left(num.begin(), num.begin()+ num.size()/2 );
        root->left = sortedArrayToBST(left);
        vector<int> right(num.begin()+ num.size()/2 +1, num.end() );
        root->right = sortedArrayToBST(right);
        return root;
    }
};

int main()
{

    Solution s;

    return 1;
}

