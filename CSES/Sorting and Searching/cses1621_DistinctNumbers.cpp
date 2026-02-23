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
    vector<int> v(n);
    unordered_set<int> s;
    s.reserve(n * 2);
    for(auto& x: v) cin >> x;
    for (auto x: v) s.insert(x);
    cout << s.size() << '\n';
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
    //cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}