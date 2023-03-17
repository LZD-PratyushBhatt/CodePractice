#include<bits/stdc++.h>
using namespace std;

int find_counts(vector<int> vec, int total_sum, int idx, int sum){
    if(sum == total_sum){
        return 1;
    }
    if(idx >= vec.size() or sum > total_sum){ //array only pisitive else remove latter
        return 0;
    }
    sum += vec[idx];
    // cout<<"Sum is (before popping) "<<sum<<endl;
    int left = find_counts(vec, total_sum, idx+1, sum);
    sum -= vec[idx];
    // cout<<"Sum is (after popping) "<<sum<<endl;
    int right = find_counts(vec, total_sum, idx+1, sum);
    // cout<<"Right is "<<right<<" and left is "<<left<<endl;
    return left + right;
}

int main(){
    int sum = 20;
    vector<int> vec{2,5,13,12,7,1};
    int total_count_of_subs = find_counts(vec, sum, 0, 0);
    cout<<total_count_of_subs<<endl;
}