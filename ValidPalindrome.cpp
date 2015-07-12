#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

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
    bool isPalindrome(char* s) {
        char* p = s;
        while(*p!='\0')
            p++;
        p--;
        while(s<p) // jima1, "!=" is not correct s->4 p->5, after s++, p--, p->4, s->5
        {
            if(!isalnum(*s)) // jima1, isalpha cannot handle "1a2" case
            {
                s++;
                continue;
            }
            if(!isalnum(*p))
            {
                p--;
                continue;
            }
            //cout<<"s is "<<*s<<", p is "<<*p<<endl;
            if( tolower(*s) != tolower(*p) )
                return false;
            s++;
            p--;
        }
        return true;

    }
};



int main()
{

    Solution s;
    assert(s.isPalindrome(" abba"));
    assert(s.isPalindrome("Ab.a"));
    assert(s.isPalindrome("abcba"));
    assert(s.isPalindrome("1a2"));

    return 1;
}

