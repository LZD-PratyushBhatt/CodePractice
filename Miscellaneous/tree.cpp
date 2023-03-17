//                       5
//                4             3
//           3       2       2        1
//         2  1    1   0  1    0      
//        1


//                          6
//                 5                    4
//          4           3            3        2
//       3     2      2   1        2   1    1
//     2   1  1      1            1
//    1
// dp[6] = 1
// dp[5] = dp[6] = 1
// dp[4] = dp[5] + dp[6] = 2
// dp[3] = dp[4] + dp[5] = 3
// dp[2] = dp[3] + dp[4] = 5
// dp[1] = dp[2] + dp[3] = 8

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[n] = 1;
    dp[n-1] = 1;
    for(int i = n-2;i>=1;i--){
        dp[i] = dp[i+1] + dp[i+2];
    }
    for(int i = 1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    vector<int> vec;
    for(int i=1;i<=n;i++)vec.push_back(dp[i]);
    return vec;
}