#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*

 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
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


class Solution1 {
public:
    void sortColors(int A[], int n) {
        int cout[3] = {0,0,0};
        for(int i=0; i<n; i++)
        {
            cout[A[i]]++;
        }
        int k =0;
        for(int i=0; i<3; i++)
        {
            for(int j =0; j<cout[i]; j++)
                A[k++] = i;
        }
    }
};
class Solution2 {
public:
    void sortColors(int A[], int n) {
        
        
    }
};

int main()
{
    
    Solution s;
    
    return 1;
}

