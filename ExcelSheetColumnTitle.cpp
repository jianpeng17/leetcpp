#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB

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
    string convertToTitle(int n) {
        vector<char> vec;
        string result;
        while(n!=0)
        {
            int i = n%26;
            char c = (i==0) ? 'Z' : ('A' + i - 1);
            //cout<<"c is "<<c<<endl;
            vec.push_back(c);
            n=(n%26==0)? ((n-26)/26) : (n/26);
        }
        reverse(vec.begin(), vec.end());
        for(vector<char>::iterator it = vec.begin(); it != vec.end(); it++)
        {
            //char c = *it;
            //cout<<"c is "<<c<<endl;
            result.append(1,*it);
            //cout<<"result is "<<result<<endl;
        }
        //cout<<"result is "<<result<<endl;

        return result;

    }
};


int main()
{

    Solution s;
    int i = 27;
    string result = s.convertToTitle(i);
    cout<<"result is "<<result<<endl;
    return 1;
}

