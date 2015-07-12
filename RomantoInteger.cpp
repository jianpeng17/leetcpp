#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
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
    inline int rMap(char c)
    {
        switch(c)
        {
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            case 'I': return 1;
            default: return 0;
        }
    }
    
public:
    int romanToInt(string s) {
        int result=0;
        for(int i=0; i<s.length(); i++)
        {
            result += rMap(s.at(i));
            if( (i-1>=0) && rMap(s.at(i)) > rMap(s.at(i-1)) )
                result -= 2*rMap(s.at(i-1));
                
        }
        return result;
    }
};


int main()
{

    Solution s;
    string a("CMIX");
    int i = s.romanToInt(a);
    cout<<"i is "<<i<<endl;

    return 1;
}

