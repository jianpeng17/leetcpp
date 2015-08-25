#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

*/

using namespace std;



class Solution {
public:
    bool isUgly(int num) {
    
        if(num==0) // should be num<=0
            return false;
        //assert(2 & 1 == 0);

        //while(num%2 == 0)
        while( (num&1) ==0 ) // (num&1)  this must be bracketing
            num = num>> 1;   // beter than num = num/2;
        //cout<<"1, num is "<<num<<endl;
        while(num%3 == 0)
            num /= 3;
        while(num%5 ==0)
            num /= 5;
        //cout<<"2, num is "<<num<<endl;
        if(num==1)
            return true;
        else
            return false;
        return (num==1); // good

    }
};



int main()
{

    Solution s;
    assert(s.isUgly(6));
    assert(!s.isUgly(14));

    return 1;
}

