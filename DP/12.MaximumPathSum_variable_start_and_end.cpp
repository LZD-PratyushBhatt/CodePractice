#include <bits/stdc++.h> 
using namespace std;

// For these kindof questions where start and end row have variable picking/ending point
// , just pick one row as reference, like iterate over it and pick the max by calling or whatever./



int findAnswer(vector<vector<int>> &matrix, vector<vector<int>> &dp, int row, int col){
    if(row < 0 or col <0 or col >= matrix[0].size()) return -1e8;
    if(row == 0)return matrix[0][col];
    if(dp[row][col] != -1)return dp[row][col];
    int up = findAnswer(matrix, dp, row-1, col);
    int diagl = findAnswer(matrix, dp, row-1, col-1);
    int diagr = findAnswer(matrix, dp, row-1, col+1);
    return dp[row][col] = matrix[row][col] + max(max(up, diagl), diagr);
}

int findAnswerITerative(vector<vector<int>> &matrix, int n, int m){
    vector<vector<int>> dp(n, vector<int> (m, -1));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m; j++){
            if(i == 0){
                dp[0][j] = matrix[0][j];
                continue;
            }
            int up = dp[i-1][j];
            int diagl = -1e8, diagr = -1e8;
            if(j-1 >= 0)
              diagl = dp[i-1][j-1];
            if(j+1 < m)
              diagr = dp[i-1][j+1];
            dp[i][j] = matrix[i][j] + max(up, max(diagl, diagr));
        }
    }
    int maxi = -1e8;
    for(int x: dp[n-1])maxi = max(maxi, x);
    return maxi;
}

void getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m,-1));
    int maxi = -1e8;
    for(int i = 0;i<m;i++) maxi = max(maxi, findAnswer(matrix, dp, n-1, i));
    cout<<maxi<<endl<<endl;
    cout<<findAnswerITerative(matrix, n, m);
    
}


int main(){
    int n = 4;
    int m = 4;
    vector<vector<int>> matrix{{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    getMaxPathSum(matrix);
}