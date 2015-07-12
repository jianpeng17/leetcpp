#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*

 Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 
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
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        
        int j=0;
        bool twice = false;
        for(int i=1; i<n; i++)
        {
            if(A[i] != A[j])
            {
                twice = false;
                A[++j] = A[i];
            }
            else if( A[i]==A[j] && twice==false)
            {
                twice = true;
                A[++j] = A[i];
            }
            else // ( A[i]==A[j] && twice==true)
            {
                continue;
            }
        }
        return j;
    }
};


int main()
{
    
    Solution s;
    
    return 1;
}

