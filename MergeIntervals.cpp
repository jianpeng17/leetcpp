#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

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
        for(vector<Interval>::iterator itor = intervals.begin(); itor!=intervals.end();)
        {
            if(newInterval.end < itor->start)
            {
                intervals.insert(itor, newInterval);
                return intervals;
            }
            else if(newInterval.start > itor->end)
            {
                itor++;
                continue;
            }
            else
            {
                newInterval.start = min(newInterval.start, itor->start);
                newInterval.end = max(newInterval.end, itor->end);
                itor = intervals.erase(itor); // check the return
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        for(vector<Interval>::iterator itor = intervals.begin(); itor!=intervals.end();itor++)
        {
            mergeNewIntervals(result, *itor);
        }

        return result;
    }

    void mergeNewIntervals(vector<Interval> &result, Interval& newInter) {
        for(vector<Interval>::iterator itor = result.begin(); itor!=result.end();)
        {
            if(newInter.end < itor->start)
            {
                result.insert(itor, newInter);
                return;
            }
            else if(newInter.start <= itor->end)
            {
                newInter.start = min(newInter.start, itor->start);
                newInter.end = max(newInter.end, itor->end);
                itor = result.erase(itor); // check the return
            }
            else if(newInter.start > itor->end)
            {
                itor++;
            }
        }
        result.insert(result.end(), newInter);
        return;
    }

};

class Solution1 { // wrong
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), Comp); // todo how to write comp??????????
        vector<Interval> result;
        for(vector<Interval>::iterator itor = intervals.begin(); itor!=intervals.end();itor++)
        {
            vector<Interval>::iterator it = result.lower_bound(*itor); // lower_bound only for set/map
            if(it==result.end())
            {
                result.push_back(*itor);
            }
            else
            {
                vector<Interval>::iterator endItor;//find the iterator which begin is bigger than itor->end
                for(vector<Interval>::iterator ite = it; ite!=result.end();ite++)
                {
                    if (ite->start > itor->end)
                        endItor = ite;
                }
                result.erase(it, endItor);
                result.insert(it, *itor);
            }
        }
        return result;
    }
    struct Comp
    {
        bool operator()(Interval& lhs, Interval& rhs)
        {
            if(lhs.begin<rhs.begin)
                return true;
            else
                return false;
        }
    };
};



int main()
{

    Solution s;

    return 1;
}

