#include <iostream>
#include <vector>
using namespace std;



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> k(n), h(n);
        for(int i=0;i<n;i++){
            cin>>k[i];
        }
        for(int i=0;i<n;i++)cin>>h[i];
        vector<pair<int,int>> st;
        for(int i=0;i<n;i++){
            st.push_back({k[i]-h[i], k[i]});
        }
        sort(st.begin(), st.end());
        int l=-1, r=-1, ans=0;
        for(auto it: st){
            if(it.first >= r){
                ans += (r-l)*(r-l+1)/2;
                l=it.first;
                r=it.second;
            }
            else{
                r=max(r, it.second);
            }
        }
        ans += (r-l)*(r-l+1)/2;
        cout<<ans<<endl;
    }
}
