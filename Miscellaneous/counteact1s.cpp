#include<bits/stdc++.h>
using namespace std;

int get_answer(vector<int> &vec, int k, int m){
    if(k>vec.size())return 0;
    int counter = 0;
    for(int i = 1;i<vec.size();i++) dp[i] = dp[i-1] + vec[i] == 1 ? 1:0;

    for(int i = 0 ; i <= vec.size() - k ; i++) {
        int count = vec[i] == 1?1:0;
        for(int j = i + 1 ; j <= i + k - 1; j++) {
            count = vec[j] == 1?count+1:count;
        }
        if(count == m)counter++;
    }
    return counter;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int m;
        cin>>m;
        vector<int> vec(n);
        for(auto &it: vec)cin>>it;
        int answer = get_answer(vec, k, m);
        cout<<answer<<endl;
    }
}