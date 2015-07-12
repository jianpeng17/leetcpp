#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <assert.h>
/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

using namespace std;


/*
My Note
string相加，比较大小，从大到小排序

*/



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
    string largestNumber(vector<int> & nums ) {
        vector<string> strVec;
        string result = "";

        for(int i=0; i<nums.size(); i++)
        {
            string str = std::to_string(nums[i]);
            strVec.push_back(str);
        }
        sort(strVec.begin(), strVec.end(), cmp);
        for(vector<string>::iterator it = strVec.begin(); it != strVec.end(); it++)
        {
            result += *it;
        }
        if( result[0] == '0' )
            result = "0";
        return result;
    }
    static bool cmp(string& a, string& b) // need static, need &
    {
        return (a+b) > (b+a);
    }
};



int main()
{
    vector<int> vec;
    vec.push_back(323);
    vec.push_back(3);
    vec.push_back(33);
    Solution s;
    string result = s.largestNumber(vec);
    cout<<"result is "<<result<<endl;
    return 1;
}

