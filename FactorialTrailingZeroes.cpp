#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
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


class Solution1 { // Time Limit Exceeded
public:
    int trailingZeroes(int n) {
        int sum=0;
        for(int i=1; i<=n; i++)
            sum += getFive(i);
        return sum;

    }

    int getFive(int n)
    {
        int sum = 0;
        while(n!=1)
        {
            if(n%5 != 0)
                break;
            else
            {
                sum++;
                n = n/5;
            }
        }
        //cout<<"n is "<<n<<", sum is "<<sum<<endl;
        return sum;
    }
};


class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        int tmp = 0;
        while(n/5>0)
        {
            tmp = n/5;
            sum += tmp;
            n = n/5;
        }
        return sum;

    }

};

int main()
{

    Solution s;
    cout<<s.trailingZeroes(10)<<endl;
    assert(s.trailingZeroes(10)==2);
    assert(s.trailingZeroes(15)==3);
    return 1;
}

