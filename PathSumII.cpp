#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path;

        getAllPath(root, sum, path, result);
        return result;

    }

    void getAllPath(TreeNode *root, int sum, vector<int>& path, vector<vector<int> >& result)
    {
        if(root == nullptr) // jima1, in case root is null
            return;
        path.push_back(root->val);
        if(root->left == NULL && root->right==NULL)
        {
            if( root->val == sum )
            {
                //path.push_back(root->val);
                result.push_back(path);
                //return;
            }

            else
                ;//return;
        }
        //path.push_back(root->val);
        if(root->left != nullptr) // jima1, not needed, let the null check at the begin of this routine
            getAllPath(root->left, sum-(root->val), path, result);
        if(root->right != nullptr)
            getAllPath(root->right, sum-(root->val), path, result);
        path.pop_back(); // jima1, this is very necessary
    }
};


int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(3);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node3.right = &node5;

    Solution s;
    int sum = 7;

    vector<vector<int>> result = s.pathSum(&node1,sum);
    for(int i = 0; i< result.size(); i++)
    {
        cout<<"print "<<i<<"th result"<<endl;
        vector<int>& tmp = result[i];

        for(int j=0; j<tmp.size(); j++)
        {
            cout<<tmp[j]<<" ";
        }
        cout<<endl;
    }

    return 1;
}

