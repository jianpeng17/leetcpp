#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

 Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> arr;

        generateSubsetsWithDup(arr, 0, S, result, true);
        return result;
    }

    void generateSubsetsWithDup(vector<int>& arr, int start, vector<int> &S, vector<vector<int> >& result, bool outer)
    {
        result.push_back(arr);

        cout<<"start is "<<start<<endl;
        /*
        for (auto elem : arr)
        {
            cout<<elem<<" ";
        }
        */
        cout<<endl;



        for(int i=start; i<S.size(); i++ )

        {
            //generateSubsetsWithDup(arr, start+1, S, result);
            string out = outer?"outer":"inner";
            if(i!=start && S[i]==S[i-1])
            {
                cout<<"current is "<< out <<", start is "<< start<<", i is "<< i<<", s[i] and s[i-1] is "<<S[i]<<endl;
                continue;
            }


            arr.push_back(S[i]);
            generateSubsetsWithDup(arr, i+1, S, result, false); // jima1, invoke recursively!!! so "1 2 2" can be generated
            arr.pop_back();

        }


    }
};



int main()
{

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(2);
    Solution s;
    vector<vector<int>> result = s.subsetsWithDup(vec);
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

