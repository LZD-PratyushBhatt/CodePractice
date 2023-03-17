#include<bits/stdc++.h>
using namespace std;

bool isValidBoard(vector<vector<char>> board, int row, int col, char c){
    for(int i = 0;i<9;i++){
        // row
        if(board[i][col] == c)return false;

        // col
        if(board[row][i] == c)return false;

        // the square box
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)return false;
    }
    return true;
}

bool findAnswer(vector<vector<char>> &board){
    for(int i = 0;i<board.size();i++){
        for(int j = 0; j< board[0].size();j++){
            if(board[i][j] == '.'){
                for(char c = '1'; c <= '9'; c++){
                    if(isValidBoard(board, i, j, c)){
                        board[i][j] = c;
                        if(findAnswer(board) == true)return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    bool flag = findAnswer(board);
    cout<<flag<<endl;
    for(int i = 0;i<9;i++){
        for(int j = 0; j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

}