// Problem link : https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

int findAnswer(vector<vector<int>> &grid, int i, int j, int k,vector<vector<vector<int>>> &dp){
    if(j<0 or k<0 or k>=grid[0].size() or j>=grid[0].size()) return -1e8;
    if(i == grid.size()-1){
        if(j == k)return grid[i][j]; //if both at same cell, return only once.
        return grid[i][j] + grid[i][k]; // when both are at diff cells, return 
//         Sum of both.
    }
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int directions[3] = {-1,0,1};
    int maxi = -1e8;
    for(int jj = 0;jj<3;jj++){
        for(int kk = 0;kk<3;kk++){
            if(j == k)
                maxi = max(maxi, grid[i][j] + findAnswer(grid, i+1, j+directions[jj], k+directions[kk], dp));
             else
                maxi = max(maxi, grid[i][j] + grid[i][k] + findAnswer(grid, i+1, j+directions[jj], k+directions[kk], dp));
        }
    }
    return dp[i][j][k] = maxi;
}

int findAnswerIterative(vector<vector<int>> &grid, int n, int m){
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m,-1)));
    for(int i = n-1;i>=0;i--){
        for(int j = 0;j<m;j++){
            for(int k = 0;k<m;k++){
                if(i==n-1){ // The base case.
                    if(j == k) // if same col
                        dp[i][j][k] = grid[i][j];
                    else // if diff column
                        dp[i][j][k] = grid[i][j] + grid[i][k];
                    continue;
                }
//                 There can be 9 possibilites now, 3 k's for every j, like permutations of which/where bla bla
                int directions[3] = {-1,0,1};
                int maxi = -1e8;
                for(int jj = 0;jj<3;jj++){
                    for(int kk = 0; kk<3; kk++){
                        int value = 0;
                        int j_effective = j+directions[jj];
                        int k_effective = k+directions[kk];
                        if(j == k) value = grid[i][j];
                        else value = grid[i][j] + grid[i][k];
//                         Check for bounds
                        if(j_effective >=0 and j_effective<m and k_effective>=0 and k_effective<m)
                            value+=dp[i+1][j_effective][k_effective];
                        else value+=-1e8; // Done take the answer
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j][k] = maxi;
            }
        }
    }
    return dp[0][0][m-1]; // Alice at 0,0 and rob at 0, m-1, hence returning that cell. As we went from
//     Top to bottom.
}

void maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c,-1)));
    cout<<findAnswer(grid, 0, 0, c-1,dp)<<endl;
    cout<<findAnswerIterative(grid, r, c);
}

int main(){
    int r = 3;
    int c = 4;
    vector<vector<int>> grid{{2,3,1,2},{3,4,2,2},{5,6,3,5}};
    maximumChocolates(r,c,grid);
}