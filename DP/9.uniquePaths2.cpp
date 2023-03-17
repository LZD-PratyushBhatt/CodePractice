#include<bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);
int findAnswer(int n, int m, int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(row >=0 and col >=0 and mat[row][col] == -1)return 0;
    if(row <0 or col < 0) return 0;
    if(row == 0 and col == 0)return 1;
    if(dp[row][col] != -1)return dp[row][col];
    mat[row][col] = -1;
    int left = findAnswer(n, m, row, col-1, mat, dp);
    int right = findAnswer(n, m, row-1, col, mat, dp);
    mat[row][col] = 0;
    return dp[row][col] = (left + right) % mod;
}
int findAnswerIterative(int n, int m, vector<vector<int>> &mat){
    vector<vector<int>> dp(n, vector<int> (m, -1));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i >=0 and j>=0 and mat[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            if(i == 0 and j == 0){
                dp[0][0] = 1;
                continue;
            }
            int left = 0, up = 0;
            if(j) left = dp[i][j-1];
            if(i) up = dp[i-1][j];
            dp[i][j] = (left + up) % mod;
        }
    }
    return dp[n-1][m-1];
}

void mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int> (m, -1));
    cout<<findAnswer(n, m, n-1, m-1, mat, dp)<<endl<<endl;
    cout<<findAnswerIterative(n, m, mat);
}

int main(){
    int n = 3, m =3;
    vector<vector<int>> mat{{0,0,0},{0,-1,0},{0,0,0}};
    mazeObstacles(n,m,mat);
}