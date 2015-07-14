#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

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


struct Interval {
 int start;
 int end;
 Interval() : start(0), end(0) {}
 Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        for(int i =0; i< intervals.size(); i++)
        {
            if (newInterval.end < intervals[i].start) {
                result.push_back(newInterval);
                for(int j=i; j<intervals.size(); j++)
                {
                    result.push_back(intervals[j]);
                }
                return result; // result should be returned after all left intervals are inserted
                } else if (newInterval.start > intervals[i].end) {
                result.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        result.push_back(newInterval);
        return result;
}
};

class Solution1 { // jima1, time limit exceeded, vector erase, return new iterator?
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        while (it != intervals.end()) {
            if (newInterval.end < it->start) {
                intervals.insert(it, newInterval);
                return intervals;
            } else if (newInterval.start > it->end) {
                it++;
                //continue;
            } else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = intervals.erase(it);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
}
};


int main()
{
    Interval a(1,2);
    vector<Interval> vec;
    vec.push_back(a);
    Solution s;
    Interval b(2,3);
    Interval c(3,4);
    Interval d(0,5);
    vec = s.insert(vec, b);
    for(vector<Interval>::iterator it = vec.begin(); it!=vec.end(); it++)
    {
        cout<<"print interval, start: "<<it->start<<", end: "<<it->end<<endl;
    }
    vec = s.insert(vec, c);
    for(vector<Interval>::iterator it = vec.begin(); it!=vec.end(); it++)
    {
        cout<<"print interval, start: "<<it->start<<", end: "<<it->end<<endl;
    }
    vec = s.insert(vec, d);

    for(vector<Interval>::iterator it = vec.begin(); it!=vec.end(); it++)
    {
        cout<<"print interval, start: "<<it->start<<", end: "<<it->end<<endl;
    }

    return 1;
}

