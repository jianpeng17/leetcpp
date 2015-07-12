#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
/*

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool valid[9];

        for(int i=0; i<9; i++)
        {
            fill(valid, valid+9, false);
            //resetBoolArray(valid);
            for(int j=0; j<9; j++) // check  row
            {
                if( !checkGrid(board[i][j], valid) )
                {
                    cout<<"debug 1"<<endl;
                    return false;
                }

            }

            //resetBoolArray(valid);
            fill(valid, valid+9, false);
            for(int j=0; j<9; j++) // check each column
            {
                if( !checkGrid(board[j][i], valid) )
                {
                    cout<<"debug 2, j is "<<j<<", i is "<<i<<", board grid is "<<board[i][j]<<endl;
                    return false;
                }
            }
        }

            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    //resetBoolArray(valid);
                    fill(valid, valid+9, false);
                    for(int r=0; r<3; r++)
                    {
                        for(int c=0; c<3; c++)
                        {
                            if( !checkGrid(board[3*i+r][3*j+c], valid) )
                            {
                                cout<<"debug 3"<<endl;
                                return false;
                            }
                        }
                    }

                }
            }
            return true;
    }

    bool checkGrid(char c, bool valid[9]) // jima1, reference is not need, just pass the array name
    {
        if( c=='.' ) // in case '.'-'1'
            return true;
        if( !isdigit(c) )    // jima1, use isdigit instead of isnumeric
            return false;
        if(valid[c-'1'] == true) // the index should be [c-'1']
        {
            cout<<"return false, c is "<<c<<", index is "<<c-'1'<<endl;
            return false;
        }

        return valid[c-'1'] = true; //
    }

    void resetBoolArray(bool valid[9]) // can be replaced by fill(valid, valid+9, false)
    {
        for(int i=0; i<9; i++)
            valid[i] = false;
    }

};

int main()
{
    char l1[9] = {'.','8','7','6','5','4','3','2','1'};
    vector<char> v1(l1, l1+9);

    char l2[9] = {'2','.','.','.','.','.','.','.','.'};
    vector<char> v2(l2, l1+9);

    char l3[9] = {'3','.','.','.','.','.','.','.','.'};
    vector<char> v3(l3, l1+9);

    char l4[9] = {'4','.','.','.','.','.','.','.','.'};
    vector<char> v4(l4, l1+9);

    char l5[9] = {'5','.','.','.','.','.','.','.','.'};
    vector<char> v5(l5, l1+9);

    char l6[9] = {'6','.','.','.','.','.','.','.','.'};
    vector<char> v6(l6, l1+9);

    char l7[9] = {'7','.','.','.','.','.','.','.','.'};
    vector<char> v7(l7, l1+9);

    char l8[9] = {'8','.','.','.','.','.','.','.','.'};
    vector<char> v8(l8, l1+9);

    char l9[9] = {'9','.','.','.','.','.','.','.','.'};
    vector<char> v9(l9, l1+9);

    vector< vector<char> > vec;
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    vec.push_back(v4);
    vec.push_back(v5);
    vec.push_back(v6);
    vec.push_back(v7);
    vec.push_back(v8);
    vec.push_back(v9);
    cout<<"vec[0][1] is "<<vec[1][0]<<endl;

    Solution s;
    bool result = s.isValidSudoku(vec);
    cout<<"result is "<<result<<endl;
    return 1;
}

