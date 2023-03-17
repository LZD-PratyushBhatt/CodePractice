#include<bits/stdc++.h>
using namespace std;

int functionalReturn(int n){
    if(n == 0)return 0;
    return  n + functionalReturn(n-1);
}

void nonFunctional(int i, int &total){
    if(i == 0)return;
    total = total + i;
    nonFunctional(i-1, total);
}

int main(){
    int n = 6;
    int total = 0;
    nonFunctional(n, total);
    cout<<total<<endl;
    int answer = functionalReturn(n);
    cout<<answer<<endl;
}