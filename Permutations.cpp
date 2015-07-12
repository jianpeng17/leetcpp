#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].



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
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> arr;

        genPermute(arr, num, result);
        return result;
    }

    void genPermute(vector<int>& arr, vector<int> &num, vector<vector<int> >& result)
    {
        if( arr.size() == num.size() )
        {
            result.push_back(arr);
            return;
        }
        for(int i=0; i<num.size(); i++)
        {
            if(find(arr.begin(), arr.end(), num[i]) == arr.end())
            {
                arr.push_back(num[i]);
                genPermute(arr, num, result);
                arr.pop_back();
            }
        }
    }
};


int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    Solution s;
    vector<vector<int>> result = s.permute(vec);
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

