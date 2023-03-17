// count occurence of each elmenet

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n); // same as :  int vec[n];
    for(auto &it: vec)cin>>it;

    unordered_map<int,int> hmap;
    for(int x : vec){
        hmap[x] = hmap[x] + 1; // i = i + 1 is same as i++, thats why this thing is same as hmap[x]++
    }

    for(auto it: hmap){
        cout<<it.first<< " "<<it.second<<endl;
    }
}