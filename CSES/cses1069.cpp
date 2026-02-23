#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    
    string dna;
    cin >> dna;
    char c = dna[0];
    int res = 1, count = 1;
    for (size_t i = 1; i < dna.length(); i++)
    {
        if (dna[i] == c)
        {
            count++;
        }
        else
        {
            c = dna[i];
            count = 1;
        }
        res = max(res, count);
    }
    
    cout << res << '\n';
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