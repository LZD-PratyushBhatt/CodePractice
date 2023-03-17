#include<bits/stdc++.h>
using namespace std;

int findAnswer(int m, int n, int row, int col, vector<vector<int>> &dp){
    if(row == 0 and col == 0)return 1;
    if(row < 0 or col < 0) return 0;
    if(dp[row][col] != -1)return dp[row][col];
    
    int left = findAnswer(m, n, row, col-1, dp);
    int right = findAnswer(m, n, row-1, col, dp);
    return dp[row][col] = left + right;
}

int findAnswerIter(int m, int n){
    vector<vector<int>> dp(m, vector<int> (n, -1));
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(i == 0 and j == 0){
                dp[0][0] = 1;
                continue;
            }
            int left = 0, right = 0;
            if(j-1 >=0) left = dp[i][j-1];
            if(i-1 >= 0) right = dp[i-1][j];
            dp[i][j] = left + right;
        }
    }
    return dp[m-1][n-1];
}

void uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int> (n,-1));
    cout<<findAnswer(m, n, m-1, n-1, dp)<<endl<<endl;
    cout<<findAnswerIter(m,n);
}

int main(){
    int m = 3, n = 2;
    uniquePaths(m,n);
}