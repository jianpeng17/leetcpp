#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -¡Þ.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.
Note:

Your solution should be in logarithmic complexity.

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

class Solution { // O(n) complexity
public:
    int findPeakElement(vector<int>& nums) {
        int pre = INT_MIN;
        int size = nums.size();
        for(int i=0; i<size; i++)
        {
            if(i<size-1)
            {
                if( nums[i] > pre && nums[i] >nums[i+1] )
                    return i;
            }
            if(i==size-1)
            {
                if( nums[i] >= pre ) // if nums only has -2147483648
                    return i;
            }
            pre = nums[i];
            //cout<<"pre is "<<pre<<endl;
        }

    }
};



int main()
{
    int arr[4] = {1,2,3,1};
    vector<int> vec(arr, arr+4);
    //fill(vec.begin(), vec.end(), 1);
    //for(int i=0; i<4; i++)
    //    cout<<"vec["<<i<<"] is " <<vec[i]<<endl;

    Solution s;
    int idx = s.findPeakElement(vec);
    cout <<"peak index is "<<idx<<endl;

    return 1;
}

