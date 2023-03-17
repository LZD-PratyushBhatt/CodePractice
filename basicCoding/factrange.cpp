#include<bits/stdc++.h>
using namespace std;

long long int getAllFacts(long long int n){
    if(n == 1)return 1;
    long long int ans = n*getAllFacts(n-1);
    cout<<ans<<endl;
    return ans;
}

int main(){
    long long int max_int = 10;
    getAllFacts(max_int);
}