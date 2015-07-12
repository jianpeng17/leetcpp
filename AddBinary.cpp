#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

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
    string addBinary(string a, string b) {
        string result;
        vector<char> vec;
        int al = a.size()-1;
        int bl = b.size()-1;
        int carry=0;
        for( ; al>=0 || bl>=0; al--, bl--)
        {
            int i = al<0 ? 0 : (a[al] == '0' ? 0 : 1);
            int j = bl<0 ? 0 : (b[bl] == '0' ? 0 : 1);
            int v = i+j+carry;
            cout<<"i is "<<i<<", j is "<<j<<", v is "<<v<<endl;
            switch(v)
            {
                case 0:
                    vec.push_back('0');
                    carry=0; // jima1, need to reset if carry is not needed
                    break;
                case 1:
                    vec.push_back('1');
                    carry=0;
                    break;
                case 2:
                    vec.push_back('0');
                    carry=1;
                    break;
                case 3:
                    vec.push_back('1');
                    carry=1;
                    break;
                default:
                    break;
            }
        }
        
        if(carry==1)
            vec.push_back('1');
        reverse(vec.begin(), vec.end());
        for(vector<char>::iterator it=vec.begin(); it!=vec.end(); it++)
        {
            cout<<"*it is "<<*it<<endl;
            result.append(1, *it);
        }
        return result;
    }
};
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }

        return s;
    }
};


int main()
{

    Solution s;
    string a = "1010";
    string b = "1011";
    string c = s.addBinary(a,b);
    cout<<"c is "<<c<<endl;
    return 1;
}

