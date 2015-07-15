#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 


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


class Solution1 { // sort and check equal
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) // jima1, check empty
            return false;
        sort(nums.begin(), nums.end());
        for(vector<int>::iterator it = nums.begin(); it != nums.end()-1; it++)
        {
            if(*it == *(it+1))
                return true;
        }
        return false;

    }
};
class Solution { // insert to map, if already exist, it's duplicates
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) // jima1, check empty
            return false;
        set<int> myset;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            if (myset.find(*it) != myset.end())
                return true;
            myset.insert(*it);
        }
        return false;
    }
};

class Solution3 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return unique(nums.begin(), nums.end()) != nums.end();
    }
};

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,9};
    vector<int> vec(arr, arr+10);
    Solution s;
    assert(s.containsDuplicate(vec));

    return 1;
}

