#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.


*/

using namespace std;




class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty())
            return;
        int len = nums.size();
        int j=0;
        for(int i=0; i<len; i++)
        {
            if(nums[i]!=0)
                nums[j++] = nums[i];
        }
        for(int i=j; i<len; i++)
            nums[i] = 0;
    }
};

 void moveZeroes(vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size(); i++)  {
        if (nums[i] != 0) swap(nums[i], nums[j++]);
    }
}



int main()
{

    vector<int> vec{0,1,0,3,12};

    Solution s;
    s.moveZeroes(vec);

    for(int&e:vec)
        cout<<e<<'\t';

    return 1;
}

