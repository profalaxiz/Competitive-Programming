#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

// n = 20           20! = 20 * 19 * .... * 15 * ... * 10 * ... * 5 * ... = ......0000 -> 4
// n = 5            5! = 120 -> 1
// n = 6            6! = 720
// n = 8            8! = 40320
// n = 10           10! = 3628800
// res = n / 5 ? 
// observation: 5 adds a zero, 25 adds another 0, 125 adds another 0, ...
// res = n/5 + n/25 + ...


void solve() {
    int n;
    cin >> n;
    
    int ans = 0;

    for (int x = 5; x <= n; x *= 5)
    {
        ans += n/x;
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