#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <windows.h>
/*
 Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.


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

class Solution1 { // this is for problem, no leading or trailing space, and only one space between words
public:
    void reverseWords(string &s) {
        cout<<"1"<<endl;
        reverseStr(s, 0, s.length()-1);
        //cout<<"after reverse, s is "<<s<<endl;

        int i=0;

        for(int j=0; j<s.length(); j++)
        {
            if(s[j] == ' ' )
            {
                reverseStr(s, i, j-1);
                i=j+1;
            }
            if(j==s.length()-1) // this is different, j is the last character
            {
                //cout<<"i is "<<i<<", j is "<<j<<endl;
                reverseStr(s, i, j);
            }
        }

    }
    void reverseStr(string &s, int idx1, int idx2) // string & is needed to real change
    {
        while(idx1<idx2)
        {
            char tmp = s[idx1];
            s[idx1++] = s[idx2];
            s[idx2--] = tmp;
        }
    }
};


class Solution {
public:
    void reverseWords(string &s) {
        string result="";
        int j=0;
        for(int i=s.length()-1; i>=0; )
        {
            while(s[i] == ' ' && i>=0)
                i--;
            if(i == -1)
                break;
            j=i;
            while(s[i] != ' ' && i>=0)
                i--;
            //cout<<"i is "<<i<<", j is "<<j<<endl;

            string tmp= s.substr(i+1, j-i);
            //cout<<"tmp is "<<tmp<<"!"<<endl;

            result += tmp;
            //if(i!=-1)  // jima1, don't need to add space after the last
                result += " ";


       }
       //cout<<"result is "<<result<<"!"<<endl;
       //cout<<"the index of last not space is "<<result.find_last_not_of(" ")<<endl;  // error here, should not use s.find_last_not_of(" ")
       //assert( (s.find_last_not_of(" ") +1) == 1);
       // result.erase(s.find_last_not_of(" ") +1, 1);  // use result, not s!!!!!!!!!
       result.erase(result.find_last_not_of(" ") +1, 1);  //
       //cout<<"result is "<<result<<"!"<<endl;



       s=result;
    }
};
int main()
{
    //string test("efg ");
    //cout<<"the index of last not space is "<<test.find_last_not_of(" ")<<endl;

    string a(" a ");
    //int i = a.find_last_not_of(" ");
    //cout<<"is is "<<i<<endl;
    Solution s;
    s.reverseWords(a);
    //string c = a.substr(0,1); // jima1, substr(int pos, int n) return string composed by n char starting from pos
    //cout<<"c is "<<c<<endl;
    cout<<"after reverse, string is "<<a<<"!"<<endl;

    return 1;
}

