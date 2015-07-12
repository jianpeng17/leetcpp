#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
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
    int titleToNumber(string s) {
        int result=0;
        for(int i=0; i<s.length(); i++)
        {
            int val = s[i] - 'A' + 1;
            result = result*26 + val;
        }
        return result;
    }
};



int main()
{

    Solution s;
    cout<<"AB is "<<s.titleToNumber("AB")<<endl;
    //assert(1 == s.titleToNumber("A"));
    return 1;
}

