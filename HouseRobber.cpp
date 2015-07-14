#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

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

/*
dp, choose or not choose
*/

class Solution {
public:
    int rob(vector<int> &nums) {
        int best0=0, best1=0;
        for(int i=0; i<nums.size(); i++)
        {
            int tmp = best0; // this should be save for best1 calculation
            best0 = max(best0, best1);
            best1 = tmp + nums[i];
        }
        return max(best0, best1);
    }
};


int main()
{
    
    Solution s;
    
    return 1;
}

