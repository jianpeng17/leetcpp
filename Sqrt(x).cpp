#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <assert.h>

/*

Implement int sqrt(int x).

Compute and return the square root of x.
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
    int sqrt(int x) {
        if (x<2) return x;
        if ( x==2) return 1;

        int low = 1, high = x;
        int mid, tmpMid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if( x/mid < mid)  // jima1, can not use mid*mid > x, overflow
            {
                high = mid-1; //jima1, minus 1

            }
            else if ( x/mid > mid)
            {
                low = mid+1; //jima1, plus 1
                tmpMid = mid; // this is needed, when x == 7
            }
            else
                return mid;
        }
        cout<<"x is "<<x<<endl;
        return tmpMid;
    }
};


int sqrt1(int x) {
    if (x<0) return x;

    int low = 1, high = x;
    int val;
    while(low<=high)
    {
        val = (low+high)/2;
        if( val*val > x)
            high>>=1;
        else if ( val*val < x)
            low<<=1;
        else
            return val;
        cout<<"low is "<<low<<", high is "<<high<<endl;
    }
    cout<<"val is "<<val<<endl;
    return val;
}

#define TEST(a, b) (sqrt1(a) == b)

int main()
{

    /*assert(TEST(5,2));
    cout<<"2"<<endl;
    assert(TEST(80,8));
    assert(TEST(4,2));
    assert(TEST(11,3));
    assert(TEST(13,3));
    */
    Solution s;
    cout<<s.sqrt(82)<<endl;

    for(int i=0; i<100; i++)
    {
        s.sqrt(i);
    }


    return 1;
}

