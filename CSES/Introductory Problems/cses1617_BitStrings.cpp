#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

// n = 3 
// '000' '001' '010' '011' '100' '101' ' 110' '111' --> res = 8

// n = 2
// '00' '01' '10' '11' --> res = 4

// n = 1
// '0' '1' --> res = 2

// res = 2^n 


void solve() {
    int n;
    cin >> n;
    
    // ll res = 1 << n;     -- doesn't work for big n

    ll res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = (res*2) % MOD;
    }
    
    cout << res << '\n';

    return;
}






int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}