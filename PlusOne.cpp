#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

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
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        if(digits.empty())
            return result;
        bool incre = true;
        for(vector<int>::iterator it = digits.end()-1; it>=digits.begin(); it--)
        {
            int addOne = *it;
            if(incre)
            {
                addOne += 1;
            }
            if(addOne == 10)
            {
                addOne = 0;
                incre = true;
            }
            else // reset incre
                incre = false;
            result.insert(result.begin(), addOne);
        }
        if(incre) // in case of 9.9.9
            result.insert(result.begin(), 1);
        return result;
    }
};


int main()
{

    Solution s;
    int a[3] = {9,9,9};
    vector<int> vec(a, a+3);
    vector<int> result = s.plusOne(vec);
    for(vector<int>::iterator it = result.begin(); it!=result.end(); it++)
    {
        cout<<*it<<endl;
    }

    return 1;
}

