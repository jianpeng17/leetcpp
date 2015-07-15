#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

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

// jima1, using bitset waste a lot of space
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;

        for(auto i:nums)
            used[i] = false;

        int longest = 0;
        for(auto i:nums)
        {
            if(used[i]) continue;
            int length = 1;
            used[i] = true;

            if(i!= INT_MAX) // jima1,  i+1 may overflow,
            {
                for(int j=i+1; used.find(j) != used.end(); j++)
                {
                    used[j] = true;
                    length++;
                }
            }
            if(i!= INT_MIN)
            {
                for(int j=i-1; used.find(j) != used.end(); j--)
                {
                    used[j] = true;
                    length++;
                }
            }
            longest = max(length, longest);
        }
        return longest;

    }
};



int main()
{
    int arr[7] = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
    vector<int> vec(arr, arr+7);
    Solution s;
    int result = s.longestConsecutive(vec);
    cout<<"result is "<<result<<endl;

    return 1;
}

