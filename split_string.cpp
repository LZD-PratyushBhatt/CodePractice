#include<bits/stdc++.h>
using namespace std;

int main(){
    // Code to split string by spaces, 
    // Example: str = "Pratyush Bhatt is a good boy",
    // It will be stored in vector like vec = {"Pratyush","Bhatt","is","a","good","boy"};

    string str = "this is me i am cool";
    vector<string> vec;
    string word;
    istringstream iss(str);
    while(iss>>word){
        vec.push_back(word);
    }
    // print
    for(string s: vec){ // same as for(int i=0;i<s.size();i++)
        cout<<s<<","; // then cout<< s[i]
    }
}