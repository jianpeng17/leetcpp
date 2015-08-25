#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1


*/

using namespace std;



class Solution {
public:
    bool isHappy(int n) {
        if ( n < 1)
            return false;

        unordered_set<int> myset;

        while(1)
        {
            if(myset.find(n) != myset.end())
                return false;
            myset.insert(n);
            int tmp=0;
            while(n>0)
            {
                int x = n%10;
                tmp += x*x;
                n = n/10;
            }
            if (tmp == 1)
                return true;
            cout<<"tmp is "<<tmp<<endl;

            n = tmp;
        }

        return false;

    }
};

class Solution1 {
public:
bool isHappy(int n) {
  int x = n;
  unordered_set<int> Tocheck;
    while(x>1){
        x = cal(x) ;
        if(x==1) return true ;
        if(Tocheck.find(x)!=Tocheck.end())
            return false;
        else
            Tocheck.insert(x);
    }
    return true ;
}
int cal(int n){
    int x = n;
    int s = 0;
    while(x>0){
        s = s+(x%10)*(x%10);
        x = x/10;
    }
    return s ;
}
};

int main()
{

    Solution s;
    s.isHappy(19);

    return 1;
}

