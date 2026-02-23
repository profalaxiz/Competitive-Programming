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
    vector<int> a(n); 
    vector<int> b(m);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    int i = 0, j = 0, count = 0;
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end()); 

    while (i < n && j < m)
    {
        if (a[i] - k <= b[j] && b[j] <= a[i] + k)
        {
            count++;
            i++;
            j++;
        }
        else if (b[j] < a[i] - k) j++;
        else i++;
    }

    cout << count << '\n';
    
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