#include<bits/stdc++.h>
using namespace std;

void find_answers(vector<vector<int>> &answers, vector<int> vec, int idx, vector<int> current_answer, int total_current, int sum){
    if(total_current == sum){
        // cout<<"HERERERERE"<<endl;
        answers.push_back(current_answer);
        return;
    }
    if(idx >= vec.size() or total_current>sum){ // array only +ve else remove latter
        return;
    }
   
    total_current += vec[idx];
    // cout<<"TOTal answer is "<< total_current<<endl;
    current_answer.push_back(vec[idx]);
    // for(int x: current_answer)cout<<x<< " ";
    find_answers(answers, vec, idx+1, current_answer, total_current, sum);
    current_answer.pop_back();
    total_current-=vec[idx];
    // cout<<"TOTal answer is(popped) "<< total_current<<endl;
    // for(int x: current_answer)cout<<x<< " ";
    find_answers(answers, vec, idx+1, current_answer, total_current, sum);
}

int main(){
    int sum = 20;
    vector<int> vec{2,5,13,12,7,1};
    vector<vector<int>> answers;
    find_answers(answers, vec, 0, {}, 0, sum);
    for(auto it: answers){
        for(int x: it){
            cout<<x<< " ";
        }
        cout<<endl;
    }
}