#include<bits/stdc++.h>
using namespace std;

int main(){

    string s = "1234";

    while(next_permutation(s.begin(), s.end())){
        cout<<s<<endl;
    } 
}