#include<bits/stdc++.h>
using namespace std;

void findPerm(string str, vector<string> &answers, string current_output, int idx){
    if(idx >= str.size()){
        answers.push_back(current_output);
        return;
    }
    current_output.push_back(str[idx]); // Take case 
    findPerm(str, answers, current_output, idx + 1);
    current_output.pop_back(); // Dont take case
    findPerm(str, answers, current_output, idx + 1);
}

int main(){
    string str = "321";
    vector<string> answers;
    findPerm(str, answers, "", 0);
    for(string s: answers){
        cout<<s<<endl;
    }
}