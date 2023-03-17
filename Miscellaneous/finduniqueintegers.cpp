#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    unordered_set<string> numbers;
    s.push_back('a');
    string word = "";
    for(int i=0;i<s.size();i++){
        if(!isdigit(s[i])){
            if(word!=""){
                word.erase(0, min(word.find_first_not_of('0'), word.size()-1));
                numbers.insert(word);
                word = "";
            }
        }
        else {
            word.push_back(s[i]);
        }
    }
    cout<<numbers.size()<<endl;
}
