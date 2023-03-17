#include<bits/stdc++.h>
using namespace std;

int main(){
    int number = 1234;

    int reversed_number = 0;

    while(number){
        int rem = number%10;
        reversed_number = reversed_number*10 + rem;
        number /= 10;
    }
    cout<<reversed_number<<endl;
}