#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

 Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

    A naive implementation of the above process is trivial. Could you come up with other methods?
    What are all the possible results?
    How do they occur, periodically or randomly?
    You may find this Wikipedia article useful.

*/

using namespace std;

// case, num=0, num=9

class Solution {
public:
    int addDigits(int num) {
        if (num==0)
            return 0;
        return (num%9==0) ? 9 : (num%9);

    }
};

class Solution {
public:
    int addDigits(int num) {

        return num-9*((num-1)/9);

    }
};


int main()
{

    Solution s;
    assert (s.addDigits(9)==9);
    assert (s.addDigits(1)==1);
    assert (s.addDigits(13)==4);
    assert (s.addDigits(0)==0);

    return 1;
}

