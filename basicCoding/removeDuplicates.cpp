// remove duplicates from array

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
// // Method 1 of taking input
//     vector<int> vec;
//     for(int i = 0;i<n;i++){
//         int x;
//         cin>>x;
//         vec.push_back(x);
//     }
// // Method 2
//     vector<int> vec(n);
//     for(int i = 0;i<n;i++)cin>>vec[i];

// Method 3 
    vector<int> vec(n);
    for(auto &it: vec) cin>>it;

    for(int x: vec)cout<<x<< " ";     //enhanced for loop
    cout<<endl;

    // remove duplicates
    // THROUGH SET YOU CANT SOLVE, unordered_map and unorderd_set doesn't have any order when they store things,
    // meaning they might have different order than the vector that you are creating them from.
    // set<int> ss;
    // for(int x: vec) ss.insert(x);

    // for(int x: ss)cout<<x<< " ";

    unordered_map<int, int> hmap;
// 1 2 11 1 5 2 4 6 
    // 1 :  
    // hmap[1] = true
    // answer = {1}
    // 2: 
    // hmap[2] = true
    // answer = {1,2}
    // 11:
    // hmap[11] = true
    // answer = {1,2,11}
    // 1:
    // but hmap.count(1) != 0 
     

    //if you want to check if an element exists in a hashmap, then use hashmap_name.count(ele)
    vector<int> answer;
    for(int x: vec){
        if(!hmap.count(x)){ //means x is not inside hmap
            hmap[x] = 1113423; // just to make an entry 
            answer.push_back(x);
        }
    }

    for(int x: answer)cout<<x<< " ";

}