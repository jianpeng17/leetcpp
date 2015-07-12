#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

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


class Solution1 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for(int i =0; i<32; i++)
        {
            if (n&1 == 1)
            {
                cout<<"here"<<endl;
                result = ( result == 0 ) ? 1 : ( result<<1)+1;  // jima1, result<<1+1 is equal to result<<2, which is incorrect, parencis is needed
            }
            else
            {
                result <<=1;
            }
            n>>=1;
            cout<<"n is "<<n<<", result is "<<result<<endl;

        }
        return result;
    }
};
  class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t res=0;
            for(int i=0; i<32; i++){
                res += (n>>i & 1) * (1 << (31-i));
            }
            return res;
        }

};


int main()
{

    Solution1 s;
    cout<<"3 after reverse is "<<s.reverseBits(3)<<endl;

    return 1;
}

