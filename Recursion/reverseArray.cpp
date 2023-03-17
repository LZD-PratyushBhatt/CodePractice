#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &vec, int low){
    if(low>vec.size()/2)return;
    swap(vec[low], vec[vec.size()-low-1]);
    reverseArray(vec, low+1);
}

int main(){
    vector<int> vec{1,2,3,4,5,6};
    cout<<"Array before reversing\n";
    for(int x: vec)cout<<x<<" ";
    reverseArray(vec, 0);
    cout<<"\n\nArray after reversing\n";
    for(int x: vec)cout<<x<<" ";
}