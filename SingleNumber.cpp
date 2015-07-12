#include <iostream>
#include <map> 
#include <vector>


/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

*/

/*
My Note
�����Ը�һ��map�� key��ֵ��value��count��map���ú󣬷���count��1��key

*/

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int x = 0
        for(int i=0; i<n; i++)
            x ^= A[i];
        return x;
    }
};

int main()
{
    
    Solution s;
    
    return 1;
}

