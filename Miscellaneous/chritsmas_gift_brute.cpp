#include<bits/stdc++.h>
#define mod 10000000007
using namespace std;

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for(auto &it: vec)cin>>it;

    unordered_map<int,int> freq;
    int max_beauty = 0;
    for (int i = 0; i <= n - k; i++) {
        freq.clear();
        for (int j = i; j < i + k; j++) {
            freq[vec[j]]++;
        }
        int beauty = 0;
        for(auto it: freq){
            beauty = (beauty + power(it.first, it.second)) % mod;
        }
        max_beauty = max(max_beauty, beauty);
    }
    cout << max_beauty << endl;
}