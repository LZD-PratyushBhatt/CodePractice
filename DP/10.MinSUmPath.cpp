#include <bits/stdc++.h> 
using namespace std;

int findAnswer(vector<vector<int>> &grid, vector<vector<int>> &dp,
              int row, int col){
    if(row <0 or col <0) return INT_MAX;
    if(row == 0 and col == 0) return grid[0][0];
    if(dp[row][col] != -1)return dp[row][col];
    int left = findAnswer(grid, dp, row-1, col);
    int up = findAnswer(grid, dp, row, col-1);
    return dp[row][col] = grid[row][col] + min(left,up);
}

int findAnswerIterative(vector<vector<int>> &grid, int n, int m){
    vector<vector<int>> dp(n, vector<int> (m, -1));
    for(int i = 0 ;i< n;i++){
        for(int j = 0;j<m; j++){
            if(i ==0 and j == 0){
                dp[0][0] = grid[0][0];
                continue;
            }
            int left = INT_MAX, up = INT_MAX;
            if(i-1 >=0)
               left = dp[i-1][j];
            if(j-1 >=0)
                up = dp[i][j-1];
            dp[i][j] = grid[i][j] + min(left, up);
        }
    }
    return dp[n-1][m-1];
}

void minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m,-1));
    cout<<findAnswer(grid, dp, n-1, m-1)<<endl<<endl;
    cout<<findAnswerIterative(grid, n, m);
}

int main(){
    vector<vector<int>> grid{{1,2,3},{4,5,4},{7,5,9}};
    minSumPath(grid);
}