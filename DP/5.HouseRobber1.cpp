// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

#include<bits/stdc++.h>
using namespace std;

int findAns(vector<int> nums){
    int n = nums.size();
    if(n == 0)return 0;
    if(n <= 2)return nums[n-1];
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2;i<n;i++){
        int left = nums[i] + dp[i-2]; // pick the element and i-2 because cant select adjacent.
        int right = 0 + dp[i-1]; //Dont pick the element hence the 0, and can select the adjacent now.
        dp[i] = max(left, right);
    }
    return dp[n-1];
}

int findAnsRec(vector<int> nums, vector<int> &dp, int idx){
    if(idx == 0)return nums[0]; // best answer till idx 0 is to pick that itself
    if(idx < 0)return 0; // check if index became negative
    if(dp[idx] != -1)return dp[idx]; // check if already solved.

    // Pick the current idx
    int left = nums[idx] + findAnsRec(nums, dp, idx - 2); // -2 because dont wanna pick adjacent element
    int right = 0 + findAnsRec(nums, dp, idx - 1); // -1 because can pick adjacent element. And 0 because didnt pick this one.
    return dp[idx] = max(left, right); // Best for both till the current index idx.
}

int main(){
    vector<int> nums{2,7,9,3,1};
    vector<int> dp(nums.size(), -1);
    int ansRec = findAnsRec(nums, dp, nums.size()-1);
    cout<<ansRec<<endl;

    int ansIter = findAns(nums);
    cout<<ansIter<<endl;

}