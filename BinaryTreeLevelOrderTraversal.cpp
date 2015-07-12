#include <iostream>
#include <map>
#include <vector>
#include <queue>

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]



*/

/*
My Note
注意返回是vector<vector<int>>
用一个queue保存层次的node
遍历一个level的时候，用vector保存下面层次的node，最后再一个一个插入到queue里

*/

using namespace std;


typedef vector<vector<int>> Vecvec;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
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

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        Vecvec vecvec;
        if (!root)
            return vecvec;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty())
        {
            vector<TreeNode*> treeNodeRow;
            vector<int> vec;
            while(!nodeQueue.empty())
            {
                vec.push_back( (nodeQueue.front())->val );

                if ( (nodeQueue.front())->left)
                    treeNodeRow.push_back( (nodeQueue.front())->left );
                if ( (nodeQueue.front())->right)
                    treeNodeRow.push_back( (nodeQueue.front())->right );
                nodeQueue.pop();
            }
            for(vector<TreeNode*>::iterator rowItor = treeNodeRow.begin(); rowItor != treeNodeRow.end(); rowItor++)
            {
                nodeQueue.push(*rowItor);
            }
            vecvec.push_back(vec);
        }
        return vecvec;
    }
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;

    TreeNode node4(4);
    TreeNode node5(5);
    node2.left = &node4;
    node2.right = &node5;

    TreeNode node6(6);
    TreeNode node7(7);
    node3.left = &node6;
    node3.right = &node7;

    TreeNode node8(8);
    TreeNode node9(9);
    node4.left = &node8;
    node4.right = &node9;

    TreeNode node10(10);
    node5.left = &node10;


    Solution s;
    Vecvec vecvec = s.levelOrder(&node1);

    for(VecVecItor itor1 = vecvec.begin(); itor1 != vecvec.end(); itor1++)
    {
        for(VecItor itor2 = itor1->begin(); itor2 != itor1->end(); itor2++)
        {
            cout<<*itor2<<", ";
        }
        cout<<endl;

    }

    cout<<"new experiment!!!!!!!!!!!!"<<endl;
    Solution1 s1;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> bst(a, a+10);
    TreeNode* r = s1.sortedArrayToBST(bst);
    Vecvec vecvec2 = s.levelOrder(r);

    for(VecVecItor itor1 = vecvec2.begin(); itor1 != vecvec2.end(); itor1++)
    {
        for(VecItor itor2 = itor1->begin(); itor2 != itor1->end(); itor2++)
        {
            cout<<*itor2<<", ";
        }
        cout<<endl;

    }

    return 1;
}

