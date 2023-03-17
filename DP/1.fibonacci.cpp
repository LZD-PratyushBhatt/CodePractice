#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int> &dp){
    if(n<=2)return n-1;
    if(dp[n]!=-1)return dp[n];

    return dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
}

int fiboIterative(int n){
    if(n<=2)return n-1; // n >=1
    int a = 0;
    int b = 1;
    int fibo = 0;
    for(int i = 3; i<=n;i++){
        fibo = a + b;
        a = b;
        b = fibo;
    }
    return fibo;
}

int main(){
    // 0 1 1 2 3 5 8
    int n = 7;
    vector<int> dp(n + 1,-1);
    int answer = fibonacci(n, dp);
    cout<<answer<<endl;

    cout<<endl<<endl;
    int answer2 = fiboIterative(n);
    cout<<answer2<<endl;
}