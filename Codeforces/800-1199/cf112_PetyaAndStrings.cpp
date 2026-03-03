#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    
    string s1;
    string s2;
    cin >> s1 >> s2;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        if (tolower(s1[i]) < tolower(s2[i])) { cout << "-1" << '\n'; return; }
        else if (tolower(s1[i]) > tolower(s2[i])) { cout << "1" << '\n'; return; }
    }
    
    cout << "0" << '\n';
    
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