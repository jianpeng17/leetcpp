#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*

Implement pow(x, n).
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
    double pow(double x, int n) {
        bool neg = false;
        double result = 1.0;
        if(x>-0.0000001 && x<0.0000001) // how to compare double with 0
            return 0;

        if(n<0)
        {
            neg = true;
            n = -n;
        }


        result = powWithUnsignedExponent(x, n);
/*
        if(neg)
            result = 1.0/result;
        return result;
        */
        return neg ? 1.0/result : result;

    }
    double powWithUnsignedExponent(double x, unsigned int n)
    {
        if ( n==0 )
            return 1;
        if ( n==1 )
            return x;

        double result = powWithUnsignedExponent(x, n>>1);
        result *= result;
        if(n & 0x1 == 1)
            result = result * x ;
        return result;
    }
};


int main()
{

    Solution s;
    double i = 2.5;
    cout<<"result is "<< s.pow(i, 2)<<endl;
    return 1;
}

