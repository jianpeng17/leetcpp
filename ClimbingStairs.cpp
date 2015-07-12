#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
*/

/*
My Note
就是fibonaci数列
预先定义数组，因为递归效率不高

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
    int climbStairs(int n) {
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int a[n];
        a[1]=1;
        a[2]=2;
        int i = 3;
        while(i<=n)
        {
            a[i] = a[i-1]+a[i-2];
            i++;  // increase
        }
        return a[n];
    }
};


int main()
{
    
    Solution s;
    
    return 1;
}

