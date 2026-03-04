#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    unordered_set<int> s;
    s.insert(s1); s.insert(s2); s.insert(s3); s.insert(s4);
    cout << 4 - s.size() << '\n';
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