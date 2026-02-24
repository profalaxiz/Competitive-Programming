#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll n, t;
vector<ll> machines_time;

bool check(ll X_time)
{
    ll products = 0;
    for (int i = 0; i < n; i++)
    {
        products += (X_time/machines_time[i]);
        if (products >= t) return true;
    }
    return products >= t;
}

void solve() {
    cin >> n >> t;
    machines_time.resize(n);
    for (auto& x: machines_time) cin >> x;
    
    ll low = 0, high = 1e18;
    ll ans = high;
    while (low <= high)
    {
        ll X = (low + high) / 2;
        if (check(X))
        {
            ans = X;
            high = X - 1;
        }
        else
        {
            low = X + 1;
        }
    }

    cout << ans << "\n";
    
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