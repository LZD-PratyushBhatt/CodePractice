#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

int n, k;
int a[100005];
map<int, int> freq;

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

signed main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max_beauty = INT_MIN;
    for (int i = 0; i <= n - k; i++) {
        freq.clear();
        for (int j = i; j < i + k; j++) {
            freq[a[j]]++;
        }
        int beauty = 0;
        for (int j = i; j < i + k; j++) {
            beauty = (beauty + power(freq[a[j]], a[j])) % mod;
        }
        max_beauty = max(max_beauty, beauty);
    }
    cout << max_beauty << endl;
    return 0;
}
