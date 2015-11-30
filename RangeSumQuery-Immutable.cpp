#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:

    You may assume that the array does not change.
    There are many calls to sumRange function.


*/

using namespace std;


//一开始的做法，效率低
class NumArray {
public:
    NumArray(vector<int> &nums) {
        vec.assign(nums.begin(), nums.end());
        size = nums.size();
    }

    int sumRange(int i, int j) {
        int sum=0;
        if ( (i<0 || i> size-1) || (j<0 || j>size-1) || (i>j) )
            return sum;
        for(int k = i; k<j; k++)
            sum += vec[k];
        return sum;
    }
private:
    vector<int> vec;
    int size;
};

class NumArray {
public:
    vector<int> accuResult;
    NumArray(vector<int> &nums) {
        int sum = 0;
        accuResult.push_back(sum);
        for(int i:nums)
        {
            sum += i;
            accuResult.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return accuResult[j+1]-accuResult[i];
    }
    
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

class NumArray {
    vector<int> ret = {0};
public:
    NumArray(vector<int> &nums) {
        for(auto n:nums) 
            ret.push_back(ret.back() + n);
    }

    int sumRange(int i, int j) {
        return ret[j+1] - ret[i];
    }
};


class NumArray {
public:
    NumArray(vector<int> &nums) {
        m_Sum.reserve(nums.size());

        if(nums.size() > 0)
        {
            m_Sum.push_back(nums[0]);
            for(int i = 1; i < nums.size(); i++)
                m_Sum.push_back(m_Sum[i-1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if( i < 0 || i >= m_Sum.size() || j < 0 || j >= m_Sum.size())
            return 0;
        else if(j >= i)
        {
            if(i > 0)
                return m_Sum[j] - m_Sum[i-1];
            else
                return m_Sum[j];
        }
        else
            return 0;
    }

    vector<int> m_Sum;
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
    int accum=0;
    for(int i=0;i<nums.size();i++)
        {
        accum+=nums[i];
        _acarray.push_back(accum);
        }
    }

    int sumRange(int i, int j) {
        if(i==0)
            return (_acarray[j]);
        else 
            return (_acarray[j]-_acarray[i-1]);
    }

private:
    vector<int> _acarray;
};

//Use a vector to store the sum from 0 to i.

class NumArray {
public:
    vector<int> memo = {0};
    NumArray(vector<int> &nums) {
        int summ = 0;
        for (int n : nums) {
            summ += n;
            memo.push_back(summ);
        }
    }

    int sumRange(int i, int j) {
        return memo[j+1] - memo[i];
    }
};

//I really want to know why this is a DP problem.
//Because in fellow up, it says this method will be call many times. So it is a best idea to store your result every time for the future using. For example, if you firstly call sumRange(1, 2) and sumRange(3, 4). If you call sumRange(1, 4) next time, you don't need to calculate sum from 1...4, just check the table and get result.

//C++ O(1) queries - just 2 extra lines of code
class NumArray {
public:
    NumArray(vector<int> &nums) : psum(nums.size()+1, 0) {
        partial_sum( nums.begin(), nums.end(), psum.begin()+1);
    }

    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
private:
    vector<int> psum;    
};

int main()
{
    
    Solution s;
    
    return 1;
}

