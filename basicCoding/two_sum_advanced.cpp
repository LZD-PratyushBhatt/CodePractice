// ALL THE TWO SUMS VARIATION

#include<bits/stdc++.h>
using namespace std;

pair<int,int> get_any_two_sum(vector<int> &arr, int target){
    unordered_map<int,int> mmap; // The second int doesnt matter at all, its just making sure that key gets a value and 
    // gets inserted in hashmap, same thing can be done by unordered_map<int,bool> and then mmap[x] = true or false, doesnt matter. 
    // Same thing can also be done by unordered_set<int> 

    for(int i=0; i<arr.size(); i++){
        int remaining = target - arr[i];
        if(mmap.count(remaining)) return {arr[i], remaining}; // return as soon as you find it, else if you want to print it in the same 
        // function itself, then store it in a pair, and then break instead of return.
        mmap[arr[i]]++; // you come here only when you dont find the two sum, because if you find it you return from there only.
        // Therefore no need of else and then putting it.(BE SMART and CLEAN)
    }
    return {-1,-1}; // if no answer found

    // //  ========================= Unordered_map with bool approach =============================

    // unordered_map<int,bool> mmap;
    // for(int x: arr){
    //     int remaining = target - x;
    //     if(mmap.count(remaining)) return {x, remaining};
    //     mmap[x] = true;  // doesnt matter true or false, anything you put is just making sure that key gets in the hashmap,
    //     // and then mmap.count will know that this key is there. SO, values doesnt matter here.
    // }
    // return {-1,-1}; // if no answer found

    // // =========================== unordered_set approach ==========================
    
    // unordered_set<int> mset;
    // for(int x: arr){
    //     int remaining = target - x;
    //     if(mset.count(remaining)) return {x, remaining};
    //     mset.insert(x); 
    // }
    // return {-1,-1}; // if no answer found
}

pair<int,int> get_any_two_sum_index(vector<int> &arr, int target){
    unordered_map<int,int> mmap; //this time second int stores index instead of value.

    for(int i=0;i<arr.size();i++){
        int remaining = target - arr[i];
        if(mmap.count(remaining)) return {i, mmap[remaining]}; // mmap[remaining] will get the index of that other number
        mmap[arr[i]]++;
    }
    return {-1,-1}; // if no answer found
}

vector<pair<int,int>> get_all_two_sums(vector<int> &arr, int target){
    vector<pair<int,int>> answers;
    unordered_map<int,int> mmap;

    for(int i = 0;i<arr.size();i++){
        int remaining = target - arr[i];
        if(mmap.count(remaining)) answers.push_back({arr[i], remaining}); // dont return just put things in vector.
        mmap[arr[i]]++; 
    }
    return answers;
}

vector<pair<int,int>> get_all_two_sums_no_duplicates(vector<int> &arr, int target){
    vector<pair<int,int>> answers;
    unordered_map<int,int> mmap;
    unordered_set<int> seen_elements_to_exclude;

    for(int i = 0;i<arr.size();i++){
        int remaining = target - arr[i];
        if(mmap.count(remaining) and seen_elements_to_exclude.count(remaining) == 0 and seen_elements_to_exclude.count(arr[i]) == 0) {
            answers.push_back({arr[i], remaining});
            // Next two lines, lets say arr[i] is 5 and remaining is 6, then you put that in set, so now what happens is,
            // if during iteration, arr[i] becomes 5 or 6 (doesnt matter), then that if condtion has checks seen_elements_to_exclude.count(remaining) == 0
            //  and seen_elements_to_exclude.count(arr[i]) == 0, these are making sure, if youve come once, then youre not allowed again.
            // when 5 and 6 occur for the first time, this seen_elements_to_exclude will not have either of them in the starting, because
            // values in set are inserted here only, when you come inside this if condition, and when do you come here?
            // when you found a two sum. 
            // In simple terms, two steps are there.
            // 1. Find the two sum
            // 2. Put that in this set, so you never come inside this if condition with these same two sum again.
            seen_elements_to_exclude.insert(arr[i]);
            seen_elements_to_exclude.insert(remaining);
        }
        mmap[arr[i]]++;
    }
    return answers;
}

int main(){
    vector<int> arr = {5,1,6,3,11,9, 0,5,6,11,3,8};
    auto ans = get_any_two_sum(arr, 11);
    cout<<"Answer for printing any two numbers equaling two sum: "<< ans.first<<" "<<ans.second<<endl;

    auto ans2 = get_any_two_sum_index(arr, 11);
    cout<<"Answer for printing any two numbers INDEXES equaling two sum: "<< ans2.first<<" "<<ans2.second<<endl;

    // Ultimate variations

    auto ans3 = get_all_two_sums(arr, 11);
    cout<<"Answer for all the two sums combinations: "<<endl;
    for(auto x: ans3){
        cout<<x.first<<" "<<x.second<<endl;
    } // This will print all, duplicated also, like in above case, 5 and 6 are occuring multiple times, so it prints every pair combination.

    auto ans4 = get_all_two_sums_no_duplicates(arr, 11);
    cout<<"Answer for all the two sums combinations with NO DUPLICATES: "<<endl;
    for(auto x: ans4){
        cout<<x.first<<" "<<x.second<<endl;
    } // This will print all, duplicated also, like in above case, 5 and 6 are occuring multiple times, so it prints every pair combination.

    // One more variation can be two print all the indices, do that yourself.
}