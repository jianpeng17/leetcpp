#include <iostream>
#include <map> 
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

using namespace std;

/*
到达一个终点，是通过它上面的点往下走，或者它左边的点往右走，这两种方式到达的，所以就是算这两种方式的和

*/

// Time Limit Exceeded
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<=0 || n<=0)
            return 0;
        if(m==1 && n==1)
            return 1;
        return uniquePaths(m-1, n)+uniquePaths(m, n-1);
    }
};

// 用二维数组记录前面的结果，一开始把第一行和第一列都设置为1
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if(m<1 || n<1) 
            return 0;
        int arr[m][n];
        for(int i=0; i<m; i++) // set the first column
            arr[i][0] = 1;
        for(int i=0; i<n; i++) // set the first row
            arr[0][i] = 1;
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
            
        }
        return arr[m-1][n-1];
        
    }
};

int main()
{
    
    Solution s;
    
    return 1;
}

