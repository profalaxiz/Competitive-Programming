#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> children(n);
    for (auto& child: children) cin >> child;
    sort(children.begin(), children.end());
    ll sum = 0;
    int l = 0, r = n - 1, count = 0;
    // 2 3 7 9
   while (l <= r)
   {
        sum = children[l] + children[r];
        if (sum <= x)
        {
            count++;
            l++;
            r--;
        }
        else{
            count++;
            r--;
        }
        
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