#include<bits/stdc++.h>
using namespace std;

void findAnswer(vector<int> &answer, vector<int> vec, int idx, int current_sum){
    if(idx >= vec.size()){
        answer.push_back(current_sum);
        return;
    }
    current_sum += vec[idx];
    findAnswer(answer, vec, idx + 1, current_sum);
    current_sum -= vec[idx];
    findAnswer(answer, vec, idx + 1, current_sum);
}

int main(){
    //  0 will automatically get appended when no-take case executes till the end.
    vector<int> vec{3,1,2};
    vector<int> answer;
    findAnswer(answer, vec, 0, 0);
    sort(answer.begin(), answer.end());
    for(int x: answer)cout<<x<<" ";
}