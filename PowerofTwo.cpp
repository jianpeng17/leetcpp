#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given an integer, write a function to determine if it is a power of two.

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
    bool isPowerOfTwo(int n) {
        // 2 power(0) is 1
        if(n<=0 )
            return false;
        int cnt=0;
        while(n>=1)
        {
            if( n&1 == 1)
                cnt++;
            n>>=1;
        }
        if (cnt == 1)
            return true;
        else
            return false;
    }
};


int main()
{

    Solution s;
    assert(s.isPowerOfTwo(4));
    assert(s.isPowerOfTwo(1));
    assert(!s.isPowerOfTwo(3));

    return 1;
}

