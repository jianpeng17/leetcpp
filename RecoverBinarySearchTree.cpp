#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?


jima1 todo, morris traversal
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
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> vec;
        //cout<<"debug 1"<<endl;
        if(root != NULL) // jima1, check null
        {
            inorder(root, vec);
        }

        TreeNode* first=NULL; // jima1, init to NULL
        TreeNode* second=NULL;
        for(vector<TreeNode*>::iterator it = vec.begin(); it != vec.end(); it++)
        {
            cout<<(*it)->val<<", ";
        }
        cout<<endl;
        //cout<<"debug 2"<<endl;
        for(vector<TreeNode*>::iterator it = vec.begin(); it != vec.end(); it++)
        {
            // need to check the last iterator
            if( it == vec.end()-1 )
                break;
            if ( (*it)->val > (*(it+1))->val )
            {
                first = *it;
                break;
            }

        }
        //cout<<"debug 3"<<endl;
        for(vector<TreeNode*>::iterator it = vec.end()-1; it > vec.begin(); it--)
        {
            if( (*it)-> val < (*(it-1))->val )
            {
                second = *it;
                break;
            }
        }
        //cout<<"debug 4"<<endl;
        if(first && second)
        {
            int tmp = second->val;
            second->val = first->val;
            first->val = tmp;
        }
        //cout<<"debug 5"<<endl;
        //cout<<"after recover, the tree is: "<<endl;
        for(vector<TreeNode*>::iterator it = vec.begin(); it != vec.end(); it++)
        {
            cout<<(*it)->val<<", ";
        }
    }
    void inorder(TreeNode *root, vector<TreeNode*>& vec)
    {
        if(root != NULL)
        {
            inorder(root->left, vec);
            vec.push_back(root);
            inorder(root->right, vec);
        }
    }
};


int main()
{
    TreeNode node1(3);
    TreeNode node2(1);
    TreeNode node3(4);
    node1.left = &node2;
    node1.right = &node3;

    TreeNode node4(5);
    TreeNode node5(2);
    node2.right = &node4;
    node3.right = &node5;
    Solution s;
    s.recoverTree(&node1);


    return 1;
}

