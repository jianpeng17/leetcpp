#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <boost/foreach.hpp>
/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

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

class BSTIterator {
private:
    vector<int> vec;
    int pos=0;
public:
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> s;
        while(!s.empty() || root)
        {
            while(root != NULL)
            {
                s.push(root);
                root=root->left;
            }
            if(!s.empty()) // remove this judgement also works
            {
                root = s.top();
                vec.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        BOOST_FOREACH(int i, vec)
            cout<<"val is "<<i<<endl;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return ( pos < vec.size() );
    }

    /** @return the next smallest number */
    int next() {
        return vec[pos++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */



int main()
{

    TreeNode a(1);
    BSTIterator it(&a);
    cout<<"next is "<<it.next()<<endl;

    return 1;
}

