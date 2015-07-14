#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.

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
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int index = size-k;
        return nums[index];

    }
};

// jima1, heap implementation
int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end());
    for (int i=1; i<k; i++){
        pop_heap(nums.begin(), nums.end()); // move the first element to end, and make_heap to the other elements
        nums.pop_back();
    }
    return nums[0];
}


int main()
{
    int a[6] = {3,2,1,5,6,4};
    vector<int> vec(a, a+6);

    Solution s;
    cout<<s.findKthLargest(vec, 2) <<endl;

    return 1;
}

