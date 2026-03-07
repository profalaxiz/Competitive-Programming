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
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    int m; 
    cin >> m;
    vector<pii> shots(m);
    for (auto& it: shots) cin >> it.first >> it.second; 
    for (auto it: shots)
    {
        int x_i = it.first - 1, y_i = it.second;
        int a_before = y_i - 1, a_after = a[x_i] - y_i;
        
        if (x_i > 0) a[x_i - 1] += a_before;
        if (x_i < n - 1) a[x_i + 1] += a_after;

        a[x_i] = 0;
    }

    for (int x: a) cout << x << '\n';
    
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