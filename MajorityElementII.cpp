#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given an integer array of size n, find all elements that appear more than ? n/3 ? times. The algorithm should run in linear time and in O(1) space.

Hint:

    How many majority elements could it possibly have?
    Do you have a better hint?

*/

using namespace std;



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;

        if(size == 0)
            return result;
        int div = size/3+1; //jima1, case: 1,2,3   2,3,3, the occurrence must be over size/3

        map<int, int> mmap;
        for(int i=0; i<size; i++)
        {
            if(mmap.find(nums[i]) != mmap.end())
            {
                mmap[nums[i]]++;
            }
            else
                mmap[nums[i]] = 1;
        }
        for(map<int, int>::iterator it = mmap.begin(); it != mmap.end(); it++)
        {
            if (it->second >= div)
                result.push_back(it->first);
        }
        return result;
    }
};


int main()
{

    Solution s;

    return 1;
}

