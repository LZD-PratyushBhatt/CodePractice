// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

#include<bits/stdc++.h>
using namespace std;

void findAnswers(vector<vector<int>> &answers, vector<int> vec, int sum, int idx, 
                 vector<int> current_answer, int current_sum){
    
    if(current_sum == sum){
        answers.push_back(current_answer);
        return;
    }
    if(idx >= vec.size() or current_sum > sum)return;
    // pick
    current_sum += vec[idx];
    current_answer.push_back(vec[idx]);
    findAnswers(answers, vec, sum, idx, current_answer, current_sum); // not idx + 1 cause we can take same 
    // element twice

    // not-pick
    current_sum -= vec[idx];
    current_answer.pop_back();
    findAnswers(answers, vec, sum, idx + 1, current_answer, current_sum); // not idx + 1 cause we dont want
    // to take the same element in this call.
   
}


int main(){
    int sum = 7;
    vector<int> vec{2,3,6,7,1};
    vector<vector<int>> answers;
    findAnswers(answers, vec, sum, 0, {}, 0);
    for(auto it : answers){
        for(int x: it)cout<<x<<" ";
        cout<<endl;
    }
}