#include <iostream>
#include <map>
#include <vector>


/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

*/
/*
My Note
vector�Ĺ��죬��a[10]������vector����vector(a, a+10)? yes [first,last)
���array size��1��ȡ�ľ���arr[0]��û����
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

