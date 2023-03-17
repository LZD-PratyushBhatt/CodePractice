// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3

#include<bits/stdc++.h>
using namespace std;
 
 int findAnswer(vector<int> nums, vector<int> &dp, int idx, int base){
        if(idx == base) return nums[base];
        if(idx < base)return 0;
        if(dp[idx] != -1)return dp[idx];
        int left = nums[idx] + findAnswer(nums, dp, idx-2, base);
        int right = 0 + findAnswer(nums, dp, idx-1, base);
        return dp[idx] = max(left, right);
    }

int rob(vector<int>& nums) {
    if(nums.size() == 1)return nums[0];
    vector<int> dp(nums.size(), -1);
    int ans1 = findAnswer(nums, dp, nums.size()-1, 1);
    fill(dp.begin(), dp.end(), -1);
    int ans2 = findAnswer(nums, dp, nums.size()-2, 0);
    return max(ans1, ans2);
}

int main(){
    vector<int> nums{1,2,3,1};
    int ans = rob(nums);
    cout<<ans<<endl;
}