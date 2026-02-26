#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

/*
the idea:
    If you draw a bounding box around a knight and the square it attacks, 
    that box will always be either a 2 x 3 rectangle or a 3 x 2 rectangle.
    Inside any 2 x 3 box, there are exactly 2 ways two knights can attack each other.
    Inside any 3 x 2 box, there are also exactly 2 ways they can attack each other.
    So, we just need to count how many 2 x 3 and 3 x 2 boxes fit on our k x k board
*/

void solve() {
    ll n;
    cin >> n;
    
    for (ll k = 1; k <= n; k++)
    {
        ll size = k * k;
        ll total_ways = size * (size - 1) / 2;
        ll attacks = 4 * (k - 1) * (k - 2);
        ll safe_ways = total_ways - attacks;
        cout << safe_ways << '\n';
    }
    
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