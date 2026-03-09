#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string row;
    for (int i = 0; i < n; i++)
    {
        cin >> row;
        string tmp;
        tmp.reserve(m * k);
        for (int j = 0; j < m; j++)
        {
            tmp.append(k, row[j]);
        }
        for (int c = 0; c < k; c++) cout << tmp << '\n';
    }
    
    
    return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }



    return 0;
}