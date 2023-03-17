#include <bits/stdc++.h>

using namespace std;

// Function to find the length of the LCS between two strings
int find_lcs(string s1, string s2, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0) {
        return 0;
    }
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    if (s1[m-1] == s2[n-1]) {
        dp[m][n] = 1 + find_lcs(s1, s2, m-1, n-1, dp);
    } else {
        dp[m][n] = max(find_lcs(s1, s2, m-1, n, dp), find_lcs(s1, s2, m, n-1, dp));
    }
    return dp[m][n];
}

// Function to generate all the longest common subsequences
void generate_lcs(string s1, string s2, int m, int n, vector<vector<int>>& dp, string curr, set<string>& result) {
    if (m == 0 || n == 0) {
        result.insert(curr);
        return;
    }
    if (s1[m-1] == s2[n-1]) {
        generate_lcs(s1, s2, m-1, n-1, dp, s1[m-1] + curr, result);
    } else {
        if (dp[m-1][n] >= dp[m][n-1]) {
            generate_lcs(s1, s2, m-1, n, dp, curr, result);
        }
        if (dp[m][n-1] >= dp[m-1][n]) {
            generate_lcs(s1, s2, m, n-1, dp, curr, result);
        }
    }
}

// Main function to print all longest common subsequences
void print_all_lcs(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    int lcs_len = find_lcs(s1, s2, m, n, dp);
    set<string> result;
    generate_lcs(s1, s2, m, n, dp, "", result);
    for (auto x: result) {
        cout << x << endl;
    }
}

// Sample usage
int main() {
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        print_all_lcs(s1, s2);
    }
}
