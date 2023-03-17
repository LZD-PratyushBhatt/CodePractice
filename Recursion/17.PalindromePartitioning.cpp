// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

#include<bits/stdc++.h>
using namespace std;

bool checkIfPalindrome(string s){
    int i = 0;
    int j = s.size()-1;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}

void findAnswer(vector<vector<string>> &answers, string s, int idx, vector<string> current_answer){
    // cout<<idx<<endl;
    if(idx == s.size()){
        answers.push_back(current_answer);
        return;
    }
    for(int i = idx;i<s.size();i++){
        string subs = s.substr(idx, i - idx +1);
        // cout<<"SUbs is "<<subs<<endl;
        if(checkIfPalindrome(subs)){
            // cout<<"HELLO\n\n";
            current_answer.push_back(subs);
            findAnswer(answers, s, i + 1, current_answer);
            current_answer.pop_back();
        }
    }
}

int main(){
    string s = "aab";
    // possible answers, [a,a,b,b],[aa,b,b],[aa,bb],[a,a,bb]
    vector<vector<string>> answers;
    // cout<<s<<endl<<endl;
    findAnswer(answers,s,0, {});
    for(auto it: answers){
        for(string s: it)cout<<s<< " ";
        cout<<endl;
    }
}