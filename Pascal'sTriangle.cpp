#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
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
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        if(numRows==0)
            return result;
        result.push_back(vector<int>(1,1));
        for(int i=2; i<=numRows; i++)
        {
            vector<int> current(i,1);
            const vector<int>& pre = result[i-2]; // not result[i-1] !!!!!!
            for(int j=1; j<i-1; j++)
            {
                current[j] = pre[j-1]+pre[j];
            }
            
            result.push_back(current);
        }
        return result;        
    }
};



int main()
{
    
    Solution s;
    
    return 1;
}

