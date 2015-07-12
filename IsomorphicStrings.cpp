#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

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
    bool isIsomorphic(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(len1 != len2)
            return false;
        map<char, char> map1;
        map<char, char> map2;
        for(int i=0; i<len1; i++)
        {
            if( checkMap(s[i], t[i], map1, map2) )
                continue;
            else
                return false;
        }
        return true;

    }

    bool checkMap(char c1, char c2, map<char, char>& map1, map<char, char>& map2)
    {

        //if ( (map<char, char>::iterator it = map1.find(c1) ) == map1.end() )
        if ( map1.find(c1) == map1.end() )
        {
            map1.insert(std::pair<char, char>(c1, c2));  // jima1, this is equal to below
            //map1.insert(make_pair(c1, c2));
        }
        if ( map2.find(c2) == map2.end() )
        {
            map2.insert(make_pair(c2, c1));
        }
        if (map1[c1] != c2 || map2[c2] != c1)
            return false;
        return true;
    }
};


int main()
{

    Solution s;
    assert(s.isIsomorphic("abb", "egg"));
    assert(s.isIsomorphic("paper", "title"));
    assert(s.isIsomorphic("abc", "dgg"));

    return 1;
}

