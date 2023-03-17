#include<bits/stdc++.h>
using namespace std;


void addedge(int u,int v,unordered_map<int, vector<int>> &adj){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){

    // 0 ->vec stores all the edges from 0
    // 1 =>vec stores all the edges from 1
    // 2 ->vec stores all the edges from 2
    // .
    // .
    // .
    // so on till 100


    unordered_map<int,vector<int>> adj;
    // Can replace int with any data type
    addedge(0,1,adj);
    addedge(1,2,adj);
    addedge(1,3,adj);
    addedge(0,4,adj);


    for(auto it: adj){
        cout<<"At idx "<<it.first<<" : ";
        for(int x: it.second)cout<<x<<" ";
        cout<<endl;
    }

}