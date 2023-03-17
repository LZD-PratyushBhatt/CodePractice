// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// FOR ANY QUESTIONS THAT REQUIES MOVING DUPS, USE SUCH METHODS. WITH LOOP.

#include<bits/stdc++.h>
using namespace std;
void findAnswer(vector<vector<int>> &answer, vector<int> dups, int idx, vector<int> current_answer){
    // no condition as we need all the subsets.
    answer.push_back(current_answer);

    for(int i = idx; i < dups.size(); i++){
        if(i > idx and dups[i] == dups[i-1])continue;
        current_answer.push_back(dups[i]);
        findAnswer(answer, dups, i + 1, current_answer);
        current_answer.pop_back();
    }
}

int main(){
    vector<int> vec{1,2,2,3,3};
    vector<vector<int>> answer;
    sort(vec.begin(), vec.end());
    findAnswer(answer, vec, 0, {});
    for(auto it: answer){
        for(int x: it)cout<<x<<" ";
        cout<<endl;
    }
}