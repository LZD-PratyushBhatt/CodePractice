#include<bits/stdc++.h>
using namespace std;

int findAnswer(vector<vector<int>> &points, vector<vector<int>> &dp, int row, int last_col){
    if(row == 0){ // it means we have come till the last row. And gotta pick the best in that
    // Just chose the max of three(exclude the picked column from idx 1).
        int maxi = 0;
        for(int i = 0;i<3;i++){
            if(i != last_col) maxi = max(maxi, points[0][i]);
        }
    return maxi;
    }
    int maxi = 0;
    for(int i = 0;i<3;i++){
        if(i!=last_col){
            int current_answer = points[row][i] + findAnswer(points, dp, row-1, i);
            maxi = max(maxi, current_answer);
        }
    }
    return dp[row][last_col] = maxi;
}


int findAnswerIter(vector<vector<int>> &points){
    vector<vector<int>> dp(points.size(), vector<int> (4,-1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    int n = points.size();
    for(int i = 1;i<n;i++){
        for(int j = 0; j<4;j++){
            int maxi = 0;
            for(int task = 0;task<3;task++){
                if(task != j){
                    int current_points = dp[i-1][task] + points[i][task];
                    maxi = max(maxi, current_points);
                }
            }
            dp[i][j] = maxi;
        }
    }
    // for(auto it: dp){
    //     for(int x: it){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[points.size()-1][3];
}

int main(){
  vector<vector<int>> points = {{10,40,70},
                                {20,50,80},
                                {30,60,90}};

  int n = points.size();
  vector<vector<int>> dp(n, vector<int> (4,-1));
  cout<<findAnswer(points, dp, n-1, 3);

  cout<<endl<<endl;
  int iterAns = findAnswerIter(points);
  cout<<iterAns<<endl;
}