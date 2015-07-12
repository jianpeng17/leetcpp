#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]


*/

using namespace std;
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector< vector<string> > result;
        vector<int> arr(n); // vector size must be init

        generateNQueen(n, 0, arr, result);
        return result;
    }

    void generateNQueen(int n, int row, vector<int>& arr, vector< vector<string> >& result)
    {
        if(row == n)
        {
            vector<string> vec;
            for(int i=0; i<n; i++)
            {
                int val = arr[i];
                string str="";;
                for(int j=1; j<=n; j++)
                {
                    str += (j == val) ? "Q" : "." ;
                }
                vec.push_back(str);
            }

            result.push_back(vec);
        }

        for(int col=1; col<=n; col++)
        {
            if( isValid(col, row, arr) ) //
            {
                arr[row] = col;
                //cout<<"current row is "<<row<<endl;
                generateNQueen(n, row+1, arr, result);
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

    void printMatrix(vector<vector<string> >  results)
    {
        for(int i=0; i<results.size(); i++)
        {
            cout<<"-------------------"<<endl;
            vector<string>& result = results[i];
            for(int j=0; j<result.size(); j++)
            {
                cout<<result[j]<<endl;
            }
        }

    }
int main()
{

    Solution s;
    printMatrix(s.solveNQueens(4));

    return 1;
}

