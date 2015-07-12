#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.


*/

/*
My Note
8778
8778/1000 = 8; 8778%10 = 8
然后获得77,(8778%1000)/10  = 77

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
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n=1;
        while(x/n >= 10)
            n = n*10;
        while(x!=0)
        {
            if(x/n != x%10) return false;
            x = (x%n)/10;
            n=n/100;
        }
        return true;
    }
};


int main()
{
    
    Solution s;
    int i;
    assert(s.isPalindrome(1));
    assert(s.isPalindrome(121));
    assert(s.isPalindrome(1221));
    assert(s.isPalindrome(3003));
    while(1)
    {
        cin>>i;
        cout<<i<<" is palindorme? " << s.isPalindrome(i)<<endl;;
    }
    
    return 1;
}

