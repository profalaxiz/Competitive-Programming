#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    vector<bool> vis(100, false);
    for (int i = a; i < b; i++) vis[i] = true;
    for (int i = c; i < d; i++) vis[i] = true;
    int ans = 0;
    for (int i = 0; i < 100; i++) ans += vis[i];
    cout << ans;

    return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}