// /If K=4, the frog can jump 1,2,3, or 4 steps at every index.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 6;
    int k = 2;
    vector<int> startHeight{30,10,60,10,60,50};

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <n ;i++){
        for(int j = 1; j <=k; j++){
            if(i-j <0)break; 
            int current_answer = abs(startHeight[i] - startHeight[i-j]) + dp[i-j];
            dp[i] = min(dp[i],current_answer);
        }
    }
    for(int x: dp)cout<<x<<" ";
}