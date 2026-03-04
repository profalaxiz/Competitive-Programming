#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    ll k, r;
    cin >> k >> r;

    int count = 1;
    int i = 1;
    ll tmp = k;
    while(++i)
    {
        if (tmp % 10 == 0 || tmp % 10 == r) { 
            cout << count << '\n'; 
            return; 
        }
        tmp = k * i;
        count++;
    }
    
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