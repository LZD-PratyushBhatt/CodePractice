// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4;
    int k = 9;
    vector<int> nums;
    int fact = 1; 
    // calculate fact till n-1, as for 4! is 4*3!, in such way find which of the 4 groups,
    // you belong, then solve for next 3! as its 3*2!, find you belong to which of the 3group,
    // and so on..
    for(int i = 1;i<n;i++){
        fact*=i;
        nums.push_back(i);
    }
    nums.push_back(n);
    k = k-1; //because of 0 based indexing
    string answer = "";
    // Stop when no numbers left in the array
    while(true){
        answer.append(to_string(nums[k/fact])); //k/fact gives you which group you belong,
        // like 9/4 tells you are in 2nd group, that gives you 2.
        nums.erase(nums.begin() + k/fact); // remove that element once picked
        if(!nums.size())break;
        k %=fact; // New k becomes the same as the remaining size group,
        // meaning first it was 9, then 9/4 was 2, so we came to 2nd group, and now
        // 9%4 is 1, meaning 1 step is remaining in the next step out next 3! (because fact will
        // get reduced in next step)
        fact /= nums.size(); // reducing the group size, first it was 3!, now as groups of 4
        // is done, we now will go to groups of 3, where each group size will be 2!. Hence to do
        // that this step is there 
    }
    cout<<answer<<endl;
}