#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int x, y;
    cin >> x >> y;
    int total = 0, curr = x;
    bool flag = true;
    int jump = 1;
    while (flag)
    {
        int tmp = x + jump;
        // check if y is between where i am now (curr) and where i'm headed (tmp)
        if (y >= min(curr, tmp) && y <= max(curr, tmp)) 
        {
            total += abs(y - curr);
            flag = false;
        }
        if (flag) {
            ll dist = abs(tmp - curr);
            total += dist;
            curr = tmp;
            jump *= -2;
        }
        
    }
    cout << total << '\n';
    
    return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}