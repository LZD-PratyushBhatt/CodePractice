#include <bits/stdc++.h>
using namespace std;

vector<int> canSeePersonsCount(vector<int>& h) {
    int n= h.size();
    vector<int> ans;
    stack<int> s;
    s.push(h[n-1]); 
    ans.push_back(0);
    for(int i=n-2; i>=0; i--){   
        int c=0;
        while(!s.empty() and s.top()<h[i]){  
            s.pop();
            c++;
        }
        if(!s.empty())c++;  
        s.push(h[i]);
        ans.push_back(c);
    }
    reverse(ans.begin(),ans.end());   
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> heights(n);
    for(auto &it: heights)cin>>it;

    vector<int> result = canSeePersonsCount(heights);
    int q;
    cin>>q;
    while(q--){
        int i;
        cin>>i;
        cout<<result[i-1]<<endl;
    }
    return 0;
}
