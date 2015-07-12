#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
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

// work for "hello world", "work"
// don't work for "a "
// "abc##"
class Solution1 {
public:
    int lengthOfLastWord(const char *s) {
        if(!s)
            return 0;
        //char* p1=s;
        char* p1=const_cast<char *>(s);
        while(*p1 != '\0') // notice, it's *p1
            p1++;
        char* p2 = p1;
        while(*p2 != ' ' && p2!=(s-1)) // notice, it's *p1
            p2--;
        return p1-p2-1;
    }
};

// test  	"b   a   "
// test "a"
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(!s) return 0;
        int wordLen=0;
        int cnt=0;
        for(; *s!='\0'; s++)
        {
            if(isalpha(*s))
                cnt++;
            if(!isalpha(*s) || *(s+1)=='\0') // second condition  "ab"
            {
                if(cnt>0) // in case of "b   a   "
                    wordLen = cnt;
                cnt=0;
            }
        }
        return wordLen;
    }
};


int main()
{
    char c[12] = "hell wor";
    Solution s;

    cout<<"length of last word is "<<s.lengthOfLastWord(c)<<endl;
    return 1;
}

