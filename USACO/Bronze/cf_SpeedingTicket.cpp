#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

/*

n=3, m=3

seg max_speed
40  75
50  35
10  45

a   b
40  76
20  30
40  40

if a == seg: compare the speeds and move both pointers
if a > seg: traverse seg, a -= seg and move seg pointer
else: traverse a, seg -= a and move a pointer
keep track of the maximum over-speed in each case

40 75
10 35
50 45

40 76
20->10 30
40 40

ans = 5
*/


void solve() {
    int n, m;
    cin >> n >> m;
    vi seg(n), max_speed(n);
    for (int i = 0; i < n; i++)
    {
        cin >> seg[i] >> max_speed[i];
    }
    vi b_seg(n), b_max_speed(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b_seg[i] >> b_max_speed[i];
    }

    int ans = 0, i = 0, j = 0; 
    while (i < n && j < n)
    {
        if (b_seg[i] == seg[j])
        {
            ans = max(ans, b_max_speed[i] - max_speed[j]);
            i++;
            j++;
        }
        else if (b_seg[i] > seg[j])
        {
            ans = max(ans, b_max_speed[i] - max_speed[j]);
            b_seg[i] -= seg[j];
            j++;
        }
        else
        {
            ans = max(ans, b_max_speed[i] - max_speed[j]);
            seg[j] -= b_seg[i];
            i++;
        }
    }

    cout << ans << '\n';
    
    return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}