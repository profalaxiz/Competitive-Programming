#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

// n = 7: 1 2 3 4 5 6 7 --> can be splitted to two equal sets (sum of elements is same)
// 1 2 4 7 = 14         3 5 6 = 14      

// n = 1: 1 --> cannot
// n = 2: 1 2 --> cannot
// n = 3: 1 2 3  --> can be splitted to {1, 2}, {3}
// n = 4: 1 2 3 4 --> {1, 4}, {3, 2}
// n = 5: 1 2 3 4 5 --> cannot

// one observation: if total sum is odd => cannot split, if is even => maybe

void solve() {
    int n;
    cin >> n;
    if ((n*(n+1)/2) % 2 != 0)
    {
        cout << "NO" << '\n';
        return;
    }
    vector<int> set_A, set_B;
    ll a = 0, b = 0;
    for (int i = n; i > 0; --i)
    {
        if (a > b)
        {
            set_B.push_back(i);
            b += i;
        }
        else
        {
            set_A.push_back(i);
            a += i;
        }
    }
    if (a == b)
    {
        cout << "YES" << '\n';
        cout << set_A.size() << '\n';
        for (int x: set_A) cout << x << " ";
        cout << '\n' << set_B.size() << '\n';
        for (int x: set_B) cout << x << " ";
        cout << '\n';
    }
    else cout << "NO" << '\n';
    
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