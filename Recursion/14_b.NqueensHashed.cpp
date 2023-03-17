#include<bits/stdc++.h>
using namespace std;

// For top diagonal use, (n-1) + (col-row)
// For bottom diagonal use, col + row
// For left row, just mark 1 if you traversed it
// No need for column as iteration is done per column basis

void findAnswer(vector<vector<string>> &answers, vector<string> chess_board, int col, vector<int> left_row,
                vector<int> top_diagonal, vector<int> bottom_diagonal){
    if(col == chess_board.size()){
        answers.push_back(chess_board);
        return;
    }
    for(int row = 0;row<chess_board.size();row++){
        if(left_row[row] == 0 and bottom_diagonal[row + col] == 0 and 
            top_diagonal[chess_board.size()-1+col-row]==0){
            chess_board[row][col] = 'Q';
            left_row[row] = 1;
            bottom_diagonal[row + col] = 1;
            top_diagonal[chess_board.size() - 1 + col - row] = 1;
            findAnswer(answers, chess_board, col + 1, left_row, top_diagonal, bottom_diagonal);
            chess_board[row][col] = '.';
            left_row[row] = 0;
            bottom_diagonal[row + col] = 0;
            top_diagonal[chess_board.size() - 1 + col - row] = 0;
        }
    }
}

int main(){
    int n = 4;
    
    // ..Q.
    // Q...
    // ...Q
    // .Q..

    // .Q..
    // ...Q
    // Q...
    // ..Q.

    vector<string> chess_board(n);
    string s(n, '.');
    for(int i = 0;i<n;i++)chess_board[i] = s;
    vector<int> left_row(n,0), top_diagonal(2*n-1, 0), bottom_diagonal(2*n-1,0);
    
    vector<vector<string>> answers;
    findAnswer(answers, chess_board, 0, left_row, top_diagonal, bottom_diagonal);
    for(auto it: answers){
        for(string s: it)cout<<s<<endl;
        cout<<endl;
    }
}