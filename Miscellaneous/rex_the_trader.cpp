#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    // vector<int>
    int trades = 0; 
    int times;
    while(n){
        if(n/100){
            times = n/100;
            n = n-100*times;
            trades += times;
        }
        else if(n/20){
            times = n/20;
            n = n-20*times;
            trades += times;
        }
        else if(n/10){
            times = n/10;
            n = n-10*times;
            trades += times;
        }
        else if(n/5){
            times = n/5;
            n = n-5*times;
            trades += times;
        }
        else if(n/1){
            times = n/1;
            n = n-1*times;
            trades += times;
        }
    }
    cout<<trades;
}