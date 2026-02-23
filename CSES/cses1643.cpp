#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto& x: v) cin >> x;
    
    ll best = v[0];
    ll sum = v[0];

    for (int i = 1; i < n; i++)
    {
        sum = max(v[i], sum + v[i]);
        best = max(best, sum);
    }

    cout << best << '\n';
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