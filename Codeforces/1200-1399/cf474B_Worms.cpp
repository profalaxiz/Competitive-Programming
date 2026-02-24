#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int bs_index(const vector<int>& arr, int k)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= k)
        {
            ans = mid + 1;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    cin >> m;
    vector<int> q(m);
    for(auto& x: q) cin >> x;
    
    vector<int> P(n);
    P[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        P[i] = P[i - 1] + a[i];
    }
    for (int k = 0; k < m; k++)
    {
        int idx = bs_index(P, q[k]);
        cout << idx << '\n';
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