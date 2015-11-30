#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int IntBitSize = sizeof(int)*8;
        int arr[IntBitSize];
        //fill_n(&arr, IntBitSize, 0);  wrong
        fill_n(&arr[0], IntBitSize, 0);
        for(auto val:nums)
        {
            //cout<<"val is "<<val<<endl;
            for(int i=0; i<IntBitSize; i++)
            {
                arr[i] += ((val>>i) & 1);
                arr[i] %= 3;
            }
        }
        int result = 0;
        for(int i=0; i<IntBitSize; i++)
        {
            //cout<<"arr["<<i<<"] is "<<arr[i]<<endl;
            if(arr[i])
                result += (1<<i);
        }
        return result;
    }
};




int main()
{
    vector<int> vec = {1,1,1,2,2,2,3};
    Solution s;
    int result = s.singleNumber(vec);
    cout<<"result is "<<result<<endl;

    return 1;
}

