#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Number of binary search trees =
                     (Number of ways root can be choosen)*
                     (Number of Left binary search sub-trees) *
                     (Number of Right binary search sub-trees)
Now, since there are "n" nodes in BST and let, the number of BST be represented by C(n) for n elements.

We can find the number of BSTs recursively as :
choose 1 as root, no element  on the left sub-tree. n-1 elements on the right sub-tree.
Choose 2 as root, 1 element  on the left sub-tree. n-2 elements on the right sub-tree.
Choose 3 as root, 2 element on the left sub-tree. n-3 elements on the right sub-tree.

Similarly, for i-th element as the root, i-1 elements on the left and n-i on the right.

These sub-trees are also BSTs so we can write :

C(n) = C(0)C(n-1) + C(1)C(n-2) + .....+ C(i-1)C(n-i)..... + C(n-1)C(0)

C(0) = 1, as there is exactly 1 way to make a BST with 0 nodes. C(1) = 1, as there is exactly 1 way to make a BST with 1 node.

*/

using namespace std;


/* recursive, stack overflow
int countTrees(int n)
{
    if(n<=1)
        return 1;
    else
    {
        int sum =0;
        for(int i=1;i<=n;i++)
        {
            left = countTrees(i-1);
            right = countTrees(n - i);
            sum+= left*right;
        }
        return sum;
    }
}
*/
class Solution {
public:
    int numTrees(int n)
    {
        if(n==0)
            return 0;
        vector<int> nums(n+1, 0);
        nums[0] = 1; // jima1, need to set this

        for(int i=1; i<=n; i++)
        {
            int num=0;
            for(int j=1; j<=i; j++)
            {
                num += nums[j-1]*nums[i-j];
            }
            nums[i] = num;
        }

        return nums[n];
    }
};


int main()
{

    Solution s;

    return 1;
}

