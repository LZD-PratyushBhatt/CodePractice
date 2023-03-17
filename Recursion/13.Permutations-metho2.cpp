#include<bits/stdc++.h>
using namespace std;

void findAnswer(vector<vector<int>> &answers, vector<int> &vec, int low){
    if(low == vec.size()){
        answers.push_back(vec);
        return;
    }
    for(int i = low ; i<vec.size();i++){
        // swap and bring element at index i to index low, this way you'll place every element at that index exactly once.
        swap(vec[low], vec[i]);
        findAnswer(answers, vec, low+1); // not i+1 because we want to go to next level, like swap for next index
        swap(vec[low], vec[i]);
    }
}

int main(){
    vector<int> vec{1,2,3,4};
    vector<vector<int>> answers;
    findAnswer(answers, vec, 0);
    for(auto it: answers){
        for(int x: it)cout<<x<<" ";
        cout<<endl;
    }
}