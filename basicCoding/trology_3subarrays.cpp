#include<bits/stdc++.h>
using namespace std;

vector<long long> solve(vector<vector<int>> &A, vector<vector<int>> &B){
    int n = A.size();
    int q = B.size();
    vector<int> monsterCount(100001);
    long totalMonsters = 0;
    vector<long long> result;
    for(int i = 0;i<n;i++){
        for(int j=A[i][0];j<=A[i][1];j++){
            monsterCount[j] += A[i][2];
            totalMonsters += A[i][2];
        }
    }
    sort(B.begin(), B.end(), [](auto &a, auto &b){
        return a[0] < b[0];
    });
    long monstersDefeated = 0;
    for(int i=0;i<q;i++){
        int hcor = B[i][0];
        int hstr = B[i][1];
        while(monstersDefeated < totalMonsters && monsterCount[hcor] >0 && hstr > 0){
            int matcor = monsterCount[hcor];
            int mdefbyHero = min(matcor, hstr);
            monsterCount[hcor] -= mdefbyHero;
            monstersDefeated += mdefbyHero;
            hstr -= mdefbyHero;
        }
        cout<<totalMonsters<<" " <<monstersDefeated<<endl;
        
        result.push_back((totalMonsters - monstersDefeated));
    }
    return result;
}


int main(){
    int n;
    cin>>n;

    vector<vector<int>> A(n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    int q;
    cin>>q;
    vector<vector<int>> B(q, vector<int> (q));
    for(int i=0;i<q;i++){
        for(int j=0;j<q;j++){
            cin>>B[i][j];
        }
    }
    vector<long long> answer = solve(A, B);
    for(auto x: answer)cout<<x<<" ";

}