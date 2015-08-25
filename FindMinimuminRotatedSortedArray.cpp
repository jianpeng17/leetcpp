#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

*/

using namespace std;




class Solution {
public:
    int findMin(vector<int>& nums) {
            if(nums.size() == 1) return nums[0];
            if(nums[0] < nums[nums.size()-1]) return nums[0];
            for(int i = 0; i < nums.size()-1; i++){
                   if(nums[i] > nums[i+1]) return nums[i+1];
            }
     }
};


class Solution1 {
public:
    int findMin(vector<int>& nums) {
            if(nums.size() == 1) return nums[0];
            if(nums[0] < nums[nums.size()-1]) return nums[0];
            for(int i = 1; i < nums.size(); i++){
                   if(nums[i] < nums[i-1]) return nums[i];
            }
     }
};



int findMin(vector<int> &num) {
    int lo = 0;
    int hi = num.size() - 1;
    int mid = 0;

    while(lo < hi) {
        mid = lo + (hi - lo) / 2;

        if (num[mid] > num[hi]) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    return num[lo];
}


int main()
{
    
    Solution s;
    
    return 1;
}

