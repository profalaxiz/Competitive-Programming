#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

bool isEven(ll n) { return n % 2 == 0; }

void solve() {
    ll row, col;
    cin >> row >> col;
    
    ll layer = max(row, col);
    ll res = 0;
    if (col == layer)       // row <= col
    {
        if (!isEven(col)) res = 1LL * col * col - (row - 1);
        else res = 1LL * (col - 1) * (col - 1) + row;
    }
    else        // row > col
    {
        if (isEven(row)) res = 1LL * row * row - (col - 1);
        else res = 1LL * (row - 1) * (row - 1) + col;
    }

    cout << res << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}