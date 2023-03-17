#include<bits/stdc++.h>
using namespace std;


bool isBoardValid(vector<string> chess_board, int row, int col){
    int r = row;
    int c = col;
    // Dont need to check on right side, as we are filling from left to right
    // No need to check in for a col, as iteration is such that a queen is inserted per column, so
    // no chance of two queens in more than one row for a column.

    // Check if left side col in same row a queen is there or not.
    while(c >= 0){
        if(chess_board[row][c] == 'Q')return false;
        c--;
    }

    // Check left bottom diagonal
    r = row;
    c = col;
    while(c >= 0 and r < chess_board.size()){
        if(chess_board[r][c] == 'Q')return false;
        c--;
        r++;
    }

    //  Check left top diagonal
    r = row;
    c = col;
    while(c >= 0 and r >=0){
        if(chess_board[r][c] == 'Q')return false;
        c--;
        r--;
    }
    return true;
}

void findAnswer(vector<vector<string>> &answers, vector<string> chess_board, int col){
    if(col == chess_board.size()){
        answers.push_back(chess_board);
        return;
    }
    for(int row = 0;row<chess_board.size();row++){
        if(isBoardValid(chess_board, row, col)){
            chess_board[row][col] = 'Q';
            findAnswer(answers, chess_board, col + 1);
            chess_board[row][col] = '.';
        }
    }
}

int main(){
    int n = 4;
    vector<string> chess_board(n);
    string s(n, '.');
    for(int i = 0;i<n;i++)chess_board[i] = s;
    vector<vector<string>> answers;
    findAnswer(answers, chess_board, 0);
    for(auto it: answers){
        for(string s: it)cout<<s<<endl;
        cout<<endl;
    }
}