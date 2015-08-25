#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

*/

using namespace std;

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int arr1[26];
        int arr2[26];
        fill(arr1, arr1+26, 0);
        fill(arr2, arr2+26, 0);

        for(int i=0; i<s.size(); i++)
        {
            char c1 = s[i], c2=t[i];
            int i1 = c1-'a';
            int i2 = c2-'a';
            arr1[i1]++;
            arr2[i2]++;
        }
        for(int i=0; i<26; i++)
        {
            if(arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int count[26] = {0};
        for(auto &v : s)
            ++count[v - 'a'];
        for(auto &v : t)
            if(!count[v - 'a']--) // if count[v-'a']==0, return false, if not 0, decrement
                return false;
        return true;
    }
};



int main()
{

    Solution s;
    assert(s.isAnagram("ana", "aan"));
    assert(s.isAnagram("abcde", "edcba"));
    assert(s.isAnagram("bbcde", "edcba"));
    return 1;
}

