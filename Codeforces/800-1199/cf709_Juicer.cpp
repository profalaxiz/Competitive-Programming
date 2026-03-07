#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, b, d;
    cin >> n >> b >> d;
    vi a(n);
    for (auto& x: a) cin >> x;
    int waste = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= b) waste += a[i];
        
        if (waste > d) 
        {
            ans++;
            waste = 0;
        }
    }

    cout << ans << '\n';
    
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