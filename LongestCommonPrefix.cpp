#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Write a function to find the longest common prefix string amongst an array of strings.

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
    string longestCommonPrefix(vector<string> &strs) {
        string result="";
        if(strs.empty())
            return result;
        if(strs.size() == 1)
            return strs[0];
        result = getCommon(strs[0], strs[1]);
        for(int i=2; i<strs.size(); i++)
        {
            result = getCommon(result, strs[i]);
        }
        return result;
    }
    string getCommon(string& a, string& b)
    {
        int k=-1;
        int len = min(a.length(), b.length());
        for(int i=0; i<len; i++)
        {
            if(a[i] == b[i])
                k++;
            else
                break;
        }
        if(k!=-1)
            return a.substr(0, k+1);
        else
            return "";
    }
};
// jima1, todo, do not allocate extra space
    string longestCommonPrefix(vector<string> &strs) {
            if (strs.empty())
                return "";

            string longestPrefix = strs[0];

            for (int i = 1; i < strs.size(); ++i)
            {
                int j = 0;
                while (j < strs[i].size() && j < longestPrefix.size() && strs[i][j] == longestPrefix[j])
                {
                    ++j;
                }
                longestPrefix = longestPrefix.substr(0, j);
            }

            return longestPrefix;
        }

int main()
{
    string a="";
    string b = "ab";
    string c = "abcd";
    vector<string> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    Solution s;
    string result = s.longestCommonPrefix(vec);
    cout<<"resutl is "<<result<<endl;
    return 1;
}

