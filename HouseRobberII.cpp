#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

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

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        if(n==1)
            return nums[0];
        return max(robAssit(nums, 0, n-1), robAssit(nums, 1, n));
    }
    int robAssit(vector<int> &nums, int start, int end) {
        int best0=0, best1=0;
        for(int i=start; i<end; i++)
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

