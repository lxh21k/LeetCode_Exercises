#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool isValidSudoku(vector<vector<char>>& board){
            int row[9][10] = {0};
            int col[9][10] = {0};
            int box[9][10] = {0};
            for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                    if(board[i][j] == '.') continue;
                    int curNumber = board[i][j] - '0';
                    if(row[i][curNumber]) return false;
                    if(col[j][curNumber]) return false;
                    if(box[j/3 + (i/3)*3][curNumber]) return false; //attention (i/3)*3!=i

                    row[i][curNumber] = 1;
                    col[j][curNumber] = 1;
                    box[j/3 + (i/3)*3][curNumber] = 1;
                }
            }
            return true;
        }
};
