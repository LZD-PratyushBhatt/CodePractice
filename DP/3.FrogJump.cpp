// Given a number of stairs and a frog, the frog wants to climb from the 
// 0th stair to the (N-1)th stair. At a time the frog can climb either one or two 
// steps. A height[N] array is also given. Whenever the frog jumps from a stair i to 
// stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() 
// means the absolute difference. We need to return the minimum energy that can be used 
// by the frog to jump from stair 0 to stair N-1.


#include<bits/stdc++.h>
using namespace std;

int frogJump(vector<int> startHeight, vector<int> &dp, int n){
    if(n == 0)return 0;
    if(dp[n]!=INT_MAX) return dp[n];
    int left = abs(startHeight[n] - startHeight[n-1]) + frogJump(startHeight, dp, n-1);
    int right = INT_MAX;
    if(n > 1) right = abs(startHeight[n] - startHeight[n-2]) + frogJump(startHeight, dp, n-2);
    return dp[n] = min(left, right);
}

int frogJumpIter(vector<int> startHeight){
    vector<int> dp(startHeight.size(),INT_MAX);
    dp[0] = 0;
    dp[1] = abs(startHeight[0] - startHeight[1]);
    for(int i = 2;i<startHeight.size();i++){
        dp[i] = min(abs(startHeight[i] - startHeight[i-1]) + dp[i-1], abs(startHeight[i] - startHeight[i-2]) + dp[i-2]);
    }
    return dp[startHeight.size()-1];
}

int main(){
    vector<int> startHeight{30,10,60,10,60,50};

    int answerIter = frogJumpIter(startHeight);
    cout<<answerIter<<endl;

    vector<int> dp(startHeight.size(), INT_MAX);
    int answerRec = frogJump(startHeight, dp, startHeight.size()-1);
    cout<<answerRec<<endl;
    for(int x: dp)cout<<x<<" ";
}