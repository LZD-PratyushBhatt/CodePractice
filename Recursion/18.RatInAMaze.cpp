#include<bits/stdc++.h>
using namespace std;

char directions[4] = {'U', 'D', 'L', 'R'};
int dx[4] = {0, 0 , -1, 1};
int dy[4] = {-1, 1, 0, 0};

void findAnswer(vector<string> &answer, vector<vector<int>> maze, int n, int row, int col,
            string current_answer){

        if(maze[row][col] == 0)return;
        if(row == n-1 and col == n-1){
            answer.push_back(current_answer);
            return;
        }        

        for(int i = 0;i<4;i++){
            int newRow = row + dy[i];
            int newCol = col + dx[i];
            if(newRow >=0 and newCol >=0 and newRow < n and newCol < n){
                maze[row][col] = 0;
                current_answer.push_back(directions[i]);
                findAnswer(answer, maze, n, newRow, newCol, current_answer);
                current_answer.pop_back();
                maze[row][col] = 1;
            }
        }
    }

int main(){
    int n = 4;
    vector<vector<int>> maze{{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};

    vector<string> answer;
    findAnswer(answer, maze, n, 0, 0, "");
    for(string s: answer)cout<<s<<endl;
}