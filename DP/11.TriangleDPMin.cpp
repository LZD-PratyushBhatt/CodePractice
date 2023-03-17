#include <bits/stdc++.h> 
using namespace std;

// GOLDEN RULES
// If you are going 0 -> n in recursion, then you will go n -> 0 in tabulation(reverse you loop(s)) and vice versa.
// If you do row + 1 or anything in recurison, same will be there in tabulation
// Same base case will be there in both.


int findAnswer(vector<vector<int>> &triangle, vector<vector<int>> &dp,
              int row, int col){
    // This is the first time we are going from start to end in recursion, else we always
    // used to start from the end. Still it is Top down only.
    if(row == triangle.size()-1)return triangle[row][col];
    if(dp[row][col] != -1)return dp[row][col];
    int down = findAnswer(triangle, dp, row + 1, col);
    int diag = findAnswer(triangle, dp, row + 1, col + 1);
    return dp[row][col] = triangle[row][col] + min(down, diag);
}

int findAnswerIterative(vector<vector<int>> &triangle, int n){
    vector<vector<int>> dp(n, vector<int> (n, -1));
    for(int i = n-1; i>=0;i--){
        for(int j = i; j>=0;j--){
            if(i == n-1){
                dp[n-1][j] = triangle[n-1][j];
                continue;
            }
            int up = dp[i+1][j];
            int diag = dp[i+1][j+1];
            dp[i][j] = triangle[i][j] + min(up, diag);
        }
    }
    return dp[0][0];
}

void minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout<<findAnswer(triangle, dp, 0, 0)<<endl<<endl;
    cout<<findAnswerIterative(triangle, n);
}

int main(){
    vector<vector<int>> triangle{{1},{2,3},{3,6,7},{8,9,6,10}};
    minimumPathSum(triangle, triangle.size());
}