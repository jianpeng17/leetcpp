#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

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
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        if(size==0) return 0;
        int arr[size+1];
        fill(arr, arr+size+1, 0);
        //memset(arr, 0, sizeof(int)*(size+1));

        for(int i=0; i<size; i++)
        {
            arr[nums[i]]=1;
        }
        for(int i=0; i<size+1; i++)
        {
            if (arr[i]==0)
                return i;
        }
    }
};

class Solution { // may overflow
public:
    int missingNumber(vector<int>& nums) {
        int max_sum = nums.size()*(nums.size()+1)/2;
        int sum = 0;

        for(auto& v: nums){sum+=v;}

        return max_sum-sum;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int res(0);
        for (int i = 0; i < nums.size(); ++ i)
            res = res ^ nums[i] ^ (i + 1);
        return res;
    }
};

//The main idea is similar to the problem Single Number, we can xor all the numbers in the array and the numbers from 0 to n together, the missing number will occur only once, so the result is the missing number.



int main()
{

    Solution s;
    vector<int> vec;
    vec.push_back(0);
    int result = s.missingNumber(vec);
    cout<<"result is "<<result<<endl;
    //assert(result == 1);

    return 1;
}

