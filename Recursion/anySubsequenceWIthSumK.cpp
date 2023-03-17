// Goal is to print any subsequency and not all that matches a sum k
#include<bits/stdc++.h>
using namespace std;

bool find_answers(vector<int> vec, int idx, vector<int> &answer, int total_current, int sum){
    if(total_current == sum){
        return true;
    }
    if(idx >= vec.size() or total_current>sum){ //array only +ve else remove latter 
        return false;
    }
    total_current += vec[idx];
    answer.push_back(vec[idx]);
    if(find_answers(vec, idx+1, answer, total_current, sum) == true) return true;
    // if above is true then dont need to come below, else come below and proceed further, dont just
    // do return find_answers, because that may return when calls return false also.
    answer.pop_back();
    total_current-=vec[idx];
    if(find_answers(vec, idx+1, answer, total_current, sum) == true)return true;
    return false; // if none returned true, than no answer, hence false
}

int main(){
    int sum = 20;
    vector<int> vec{10,4,7,1,10};
    vector<int> answer;
    if(find_answers(vec, 0, answer, 0, sum))
    {
        for(int x: answer)
            cout<<x<< " ";
    }
    else cout<<"NO ANSWER\n";
    
}