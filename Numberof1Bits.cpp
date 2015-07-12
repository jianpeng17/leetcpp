#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.
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
    int hammingWeight(uint32_t n) {
        int count = 0;

        for(int i =0;i<32; i++)
        {
            if(n&1 == 1)
                count++;
            n>>=1;
        }
        return count;


    }
};

class Solution1 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for(int i =0; i<32; i++)
        {
            if (n&1 == 1)
            {
                result = ( result == 0 ) ? 1 : ( result<<1 +1);
            }
            else
            {
                result <<=1;
            }
            n>>=1;
        }
        return result;
    }
};

int main()
{
    uint32_t i = 13; // 1101 ->

    Solution1 s1;
    uint32_t m = s1.reverseBits(i);
    cout<<"m is "<<m<<endl;


    Solution s;
    int n = s.hammingWeight(i);
    cout<<"n is "<<n<<endl;
    return 1;
}

