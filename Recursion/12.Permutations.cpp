// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]


#include<bits/stdc++.h>
using namespace std;

void findAnswer(vector<vector<int>> &answer, vector<int> vec, vector<int> current_answer,
                vector<bool> freq){
    if(current_answer.size() == vec.size()){
        answer.push_back(current_answer);
        return;
    }
    for(int i = 0;i<vec.size();i++){ // from 0 because order can be anything right, its not like a subset
    // or a subsequence. {2,3,1} can be {3,2,1} or anything
        if(!freq[i]){
            current_answer.push_back(vec[i]);
            freq[i] = true;
            findAnswer(answer, vec, current_answer, freq);
            current_answer.pop_back();
            freq[i] = false;
        }
    }
}

int main(){
    vector<int> vec{2,3,1,4};
    vector<bool> freq(vec.size(), false);
    vector<vector<int>> answers;
    findAnswer(answers, vec, {}, freq);
    for(auto it: answers){
        for(int x: it)cout<<x<<" ";
        cout<<endl;
    }
}