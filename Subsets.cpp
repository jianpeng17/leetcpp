#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>


/*
 Given a set of distinct integers, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
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
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> result;
        vector<int> arr;
        generateSubsets(arr, 0, S, result);
        return result;
    }
    void generateSubsets( vector<int>& arr, int step, vector<int> &S, vector<vector<int>>& result)
    {
        if(step == S.size())  //jima1,  == instead of =, S.size() instead of result.size()
        {
            //cout<<"debug 5"<<endl;
            result.push_back(arr);
            return;
        }
        //cout<<"debug 1"<<endl;
        // subsets without S[i]
        generateSubsets(arr, step+1, S, result);
        // subsets with S[i]
        arr.push_back(S[step]);
        generateSubsets(arr, step+1, S, result);
        arr.pop_back();
    }

};



int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    Solution s;
    vector<vector<int>> result = s.subsets(vec);
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

