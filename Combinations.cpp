#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
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
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > result;
        vector<int> arr;

        getCombine( n, k, 1, 0, arr, result);
        return result;
    }

    void getCombine(int n, int k, int start, int step, vector<int>& arr, vector<vector<int>>& result)
    {
        if( step == k)
        {
            result.push_back(arr);
            return;
        }

        for(int i=start; i<=n; i++)
        {
            arr.push_back(i);
            getCombine( n, k, i+1, step+1, arr, result);  // jima1, i+1 instead of start+1
            arr.pop_back();
        }
    }
};



int main()
{

    Solution s;
    vector<vector<int>> result = s.combine(4,2);
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

