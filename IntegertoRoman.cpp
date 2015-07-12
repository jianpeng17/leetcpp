#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given an integer, convert it to a roman numeral.

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
    string str[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    //vector<string> roman;
    int n[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
public:
    string intToRoman(int num) {
        string result;
        for(int i=0; i<13; i++)
        {
            if( num/n[i]>=1 )
            {
                while( num/n[i] >= 1 )
                {
                    result += str[i];
                    num -= n[i];
                }
            }
            else
                continue;
        }
        return result;
    }
};


int main()
{

    Solution s;
    string result = s.intToRoman(4);
    cout<<"result is "<<result<<endl;

    return 1;
}

