#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    string s, t;
    cin >> s >> t;
    
    int i = 0, j = 0, n = s.length(), m = t.length();
    int pos = 1;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            pos++;
            i++;
            j++;
        }
        else j++;
    }
    
    cout << pos << '\n';
    
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