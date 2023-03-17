#include<bits/stdc++.h>
using namespace std;

bool compareUsingFrequency(pair<string,int> a, pair<string,int> b){
    return a.second>=b.second;
}

int main(){
    // Code to find frequency of words given in a string, we first break the string by space and store 
    // it in a vector, 
    // Example: str = "the word the is good the",
    // It will be stored in vector like vec = {"the","word","the","is","good","the"};
    // Frequecies will be {"the":3, "word":1, "is":1, "good":1}

    string str = "the word the is good the";
    vector<string> vec;
    string word;
    istringstream iss(str);
    while(iss>>word){
        vec.push_back(word);
    }
    // print
    for(string s: vec){ 
        cout<<s<<" ";
    }
    cout<<endl;
    // Store frequency using map
    unordered_map<string, int> hmap;
    for(string s: vec){
        hmap[s]++;
    }
    // Print the frequencies
    for(auto it: hmap){
        cout<<"Word is "<<it.first<<" and its frequency is "<<it.second<<endl;
    }


    // sort the words by there number of occurences, this method you can proceed for that purpose,
    // Example: Here "the" is 3 times, then other words are 1-1 times each, so if some word have same frequenceis,
    // Then print the smaller word first(smaller when comparing index by index, and not smaller in length,
    // example lets say we compare there and they, and till index 2 they are same, then at index 3, "there"
    // has r and "they" has y, and alphabetically y>r, so "they">"there",
    // this is very simpel to find out, lets say s = "they" and x = "there", then just do
    // bool flag = x<y; if flag is true, then it means x<y and false when x>=y)

    // Store hashmap, key and value in a vector or pairs,
    vector<pair<string,int>> v; // pair format is same as unorderd_map<string,int> format
    for(auto it: hmap){
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), compareUsingFrequency); // sort based on a comparater function
// Words sorted by their frequency
    cout<<"\n\nWords sorted by thier frequency\n";
    for(pair<string,int> pp : v){
        cout<<pp.first<<": "<<pp.second<<endl;
    }

}