#include<bits/stdc++.h>
using namespace std;

int get_answer(vector<int> houses, int target){
    int curr_sum = 0, min_len = 12345678;
    int n = houses.size();
    int start = 0, end = 0;
    while (end < n) {
        while (curr_sum <= target && end < n)
            curr_sum += houses[end++];
        while (curr_sum >= target && start < n) {
            min_len = min(min_len, end - start);
            curr_sum -= houses[start++];
        }
    }
    return min_len;
}


int main(){
    int n;
    cin>>n;
    vector<int> houses(n);
    for(auto &it : houses)cin>>it;
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int answer = get_answer(houses, x);
        if(answer == 12345678) answer = 0;
        cout<<answer<<endl;
    }
}