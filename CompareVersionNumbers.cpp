#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <boost/lexical_cast.hpp>
/*

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
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
/*

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int idx1 = version1.find('.');
        //cout<<"idx1 is "<<idx1<<endl;  idx is -1 if version has not "."
        string v1_pre = version1.substr(0, idx1);
        string v1_post = version1.substr(idx1+1, version1.size());

        //char* c1_pre; // not point to anywhere, strcpy may dump
        char c1_pre[v1_pre.size()+1];
        char c1_post[v1_post.size()+1];
        strcpy(c1_pre, v1_pre.c_str());
        int i1_pre = atoi(c1_pre);
        strcpy(c1_post, v1_post.c_str());
        int i1_post = atoi(c1_post);
        if(idx1==-1) i1_post=0;
        //cout<<i1_pre<<" "<<i1_post<<endl;
        //int i1_pre = boost::lexical_cast<int>(v1_pre);  // boost is not supported in leet
        //int i1_post = boost::lexical_cast<int>(v1_post);

        int idx2 = version2.find('.');
        string v2_pre = version2.substr(0, idx2);
        string v2_post = version2.substr(idx2+1, version2.size());
        char c2_pre[v2_pre.size()+1];
        char c2_post[v2_post.size()+1];
        strcpy(c2_pre, v2_pre.c_str());
        int i2_pre = atoi(c2_pre);
        strcpy(c2_post, v2_post.c_str());
        int i2_post = atoi(c2_post);
        if(idx2==-1) i2_post=0;
        //cout<<i2_pre<<" "<<i2_post<<endl;
        //int i2_pre = boost::lexical_cast<int>(v2_pre);
        //int i2_post = boost::lexical_cast<int>(v2_post);

        if(i1_pre!=i2_pre)
            return i1_pre>i2_pre ? 1 : -1;
        else
        {
            if(i1_post!=i2_post)
                return i1_post>i2_post ? 1 : -1;
            else
                return 0;
        }

    }
};
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vervec1;
        vector<int> vervec2;

        splitVersionString(version1, vervec1);
        splitVersionString(version2, vervec2);

        int maxI = max(vervec1.size(), vervec2.size());
        int i;
        for (i=0; i<maxI; ++i)
        {
            int v1 = i<vervec1.size() ? vervec1[i] : 0;
            int v2 = i<vervec2.size() ? vervec2[i] : 0;

            if (v1 < v2)
            {
                return -1;
            }
            else if (v1 > v2)
            {
                return 1;
            }
        }

        return 0;
    }

private:
    static void splitVersionString(string version,
                              vector<int>& vervec)
    {
        int tmp = 0;
        for(size_t i=0; i<version.size(); ++i)
        {
            if (version[i] == '0' && tmp == 0)
            {
                continue;
            }
            else if (version[i] != '.')
            {
                tmp = tmp * 10 + atoi(&version[i]);
            }
            else
            {
                vervec.push_back(tmp);
                tmp = 0;
            }
        }

        vervec.push_back(tmp);
    }
};


class Solution {
public:
int compareVersion(string version1, string version2) {

    while (version1.length() || version2.length())
    {
        int v1 = extractVersion(version1);
        int v2 = extractVersion(version2);

        if (v1 > v2)
            return 1;
        if (v1 < v2)
            return -1;
    }
    return 0;
}

int extractVersion(string& strVersion)
{
    if (strVersion.length() == 0)
        return 0;

    int pos = strVersion.find(".");
    if (pos == -1)
    {
        int nVersion = atoi(strVersion.c_str());
        strVersion = "";
        return nVersion;
    }

    int nVersion = atoi(strVersion.substr(0, pos).c_str());
    strVersion = strVersion.substr(pos + 1, strVersion.length());

    return nVersion;
}

};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(1)
        {
            if(version1.length() == 0 && version2.length() == 0)
                break;
            int n1 = extract_integer(version1);
            int n2 = extract_integer(version2);
            if(n1 < n2)
                return -1;
            else if(n1 > n2)
                return 1;
        }
        return 0;
    }
private:
    int extract_integer(string& str)
    {
        if(str.length() == 0){
            return 0;
        }
        int res = 0;
        int pos = str.find('.');
        if(pos == string::npos){
            res = atoi(str.c_str());
            str = string("");
        }
        else{
            res = atoi(str.substr(0, pos).c_str());
            str = str.substr(pos+1);
        }
        return res;
    }
};
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1;
        vector<int> vec2;
        convertToVec(version1, vec1);
        convertToVec(version2, vec2);
        int len1 = vec1.size();
        int len2 = vec2.size();
        int longer = max(len1,len2); // jima1, to get a larger or less number, use max() min()
        for(int i=0; i<longer; i++)
        {
            int v1 = i<len1 ? vec1[i] : 0;  // jima1, good
            int v2 = i<len2 ? vec2[i] : 0;
            if(v1 > v2)
                return 1;
            if(v1 < v2)
                return -1;
        }

        //if(len1 != len2)   // don't work for 1.0   1
        //  return len1>len2 ? 1 : -1;
        return 0;


    }
    void convertToVec(string& s, vector<int>& vec)
    {
        int tmp=0;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '.')  // jima1, mistake "==" for "="
            {
                vec.push_back(tmp);
                tmp=0;
            }
            else
            {
                char c=s[i];
                //cout<<"s[i] is "<<s[i]<<", tmp is "<<tmp<<", atoi is "<<atoi(&s[i])<<endl;  // atoi(s[i]) return 123, because the first address is passed
                tmp = 10*tmp + atoi(&c); // jima1 parameter for atoi is "char*"
            }
        }
        vec.push_back(tmp); // jima1, the last number, 1.2.33  33 need to be added
    }
};

int main()
{

    Solution s;

    assert( 1 == s.compareVersion("1.12", "1.1") );
    assert( -1 == s.compareVersion("1", "1.12") );
    assert( 0 == s.compareVersion("1.1", "1.1") );
    //cout<<"1.1.1 compare with 1.1 is "<<s.compareVersion("1.1.1", "1.1")<<endl;
    assert( 1 == s.compareVersion("1.1.1", "1.1") );
    return 1;
}

