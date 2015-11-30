#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

Hint:

    If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?


*/

using namespace std;

// wrong
class Solution {
public:
    bool canWinNim(int n) {
        if(n>=2 && n<=4)
            return false;
        return ((n+1)/6==0 || n/6 == 0 || (n-1)/6==0);
    }
};

class Solution {
public:
    bool canWinNim(int n) {
        if(n>=1 && n<=3)
            return true;
        if(n%4 == 0)
            return false;
        return true;
            
    }
};
/*
1   2   3   4    5    6    7    8    9    10    11    12 
1   1   1   0    1    1    1    0    1    1     1     0
*/


int main()
{
    
    Solution s;
    
    return 1;
}

