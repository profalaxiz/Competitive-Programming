#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

bool isEven(ll n) { return n % 2 == 0; }

void solve() {
    ll row, col;
    cin >> row >> col;
    vector<vll> m(row + 1, vll(col + 1, 0));
    
    for (ll i = 1; i <= row; i++)
    {
        for (ll j = 1; j <= col; j++)
        {
            if (i <= j)
            {
                if (isEven(j)) m[i][j] = 1LL * (j - 1)*(j - 1) + 1;
                else m[i][j] = 1LL * j*j - (i - 1);
            }
            else
            {
                if (isEven(i)) m[i][j] = 1LL * i*i - (j - 1);
                else m[i][j] = 1LL * (i - 1)*(i - 1) + j;
            }
        }
    }

    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
        {
            cout << m[r][c] << " ";
        }
        cout << "\n";
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