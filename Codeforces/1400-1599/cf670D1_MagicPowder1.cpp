#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

bool check(ll guess, int n, int k, vector<int>& grams_needed, vector<int>& have_grams)
{
    ll powder_needed = 0;
    for (int i = 0; i < n; i++)
    {
        ll total_needed = (ll)grams_needed[i] * guess;
        if (total_needed > have_grams[i])
        {
            powder_needed += (total_needed - have_grams[i]);
        }
        if (powder_needed > k) return false;    // too much powder
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> grams_needed(n);
    vector<int> have_grams(n);
    for (auto& g: grams_needed) cin >> g;
    for (auto& g: have_grams) cin >> g;

    int low = 0, high = 1e9, ans = -1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (check(mid, n, k, grams_needed, have_grams))
        {
            ans = mid;
            low = mid + 1;      // look for a bigger value
        }
        else high = mid - 1;    
    }
    
    cout << ans << '\n';

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