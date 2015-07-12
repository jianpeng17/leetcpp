#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

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
    int count=0;
public:
    int totalNQueens(int n) {

        //int* count = new int(0);// jima1, leak?
        vector<int> arr(n); // vector size must be init

        generateNQueen(n, 0, arr);
        return count;
    }

    void generateNQueen(int n, int row, vector<int>& arr)
    {
        if(row == n)
        {
            //cout<<"haha "<<endl;
            count++;
        }

        for(int col=1; col<=n; col++)
        {
            if( isValid(col, row, arr) ) //
            {
                arr[row] = col;
                //cout<<"current row is "<<row<<endl;
                generateNQueen(n, row+1, arr);
            }
        }
    }

    bool isValid(int col, int currentRow, vector<int>& arr)
    {
        //cout<<"debug, col is "<< col<<", row is "<<currentRow+1<<endl;
        for(int i=0; i<currentRow; i++)
        {
            if (arr[i] == col || abs(arr[i] - col) == (currentRow-i) )
                return false;
        }
        //cout<<"valid, col is "<< col<<", row is "<<currentRow+1<<endl;
        return true;
    }
};


int main()
{

    Solution s;
    int i = s.totalNQueens(4);
    cout<<"4 grid queen has "<<i<<" solutions!"<<endl;

    return 1;
}

