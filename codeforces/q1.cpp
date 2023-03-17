#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a;
        for(auto &it: a)cin>>it;
        sort(a.begin(), a.end(), greater<int>());
        // for(int x: a)cout<<x<<" ";
        if(a.size()==1)cout<<"YES\n";
        else {
            if(a[0] > a.size()) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}