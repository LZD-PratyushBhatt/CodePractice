// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]


// THIS IS PATTERN 2, all the pattern before this had two choice calls, take and not take,
// this is based on loop and then make choice.

#include<bits/stdc++.h>
using namespace std;

void findAnswers(vector<vector<int>> &answers, vector<int> vec, int target, int idx, vector<int> current_answer,
                 int current_sum){
    
    if(current_sum == target){
        answers.push_back(current_answer);
        return;
    }
    if(current_sum > target) return;

    for(int i = idx; i<vec.size();i++){
        if(i> idx and vec[i] == vec[i-1])continue; // first condition, because let say array is {1,1,2}, then
        // in second recursion, call with {1,2} meaning idx as 1, you'll lose picking this 1, as it will check it
        //  with the 0th index 1 and we dont want that, we want to compare elements that are taken in the current
        // recursion call only.
        current_sum += vec[i];
        current_answer.push_back(vec[i]);
        findAnswers(answers, vec, target, i+1, current_answer, current_sum);
        current_sum -= vec[i];
        current_answer.pop_back();
    }
    //return
}

int main(){
    vector<int> vec{1,1,1,2,2};
    int target = 4;
    vector<vector<int>> answers;
    sort(vec.begin(), vec.end());

    findAnswers(answers, vec, target, 0, {}, 0);
    for(auto it: answers){
        for(int x: it)cout<<x<<" ";
        cout<<endl;
    }
}