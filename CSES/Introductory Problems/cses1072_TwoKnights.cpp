#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

// ways to place a knight on an n*n chessboard = n
// ways to place second knight on the same chessboard = n - 1
// valid ways = total ways - attacks
// total ways = n*(n-1)/2   
// attacks:
//  2*4 + 3*8 + 4*(n-3)*4 + 6*(n-4)*4 + 8*(n-4)*(n-4)
/*
n = 14

2 3 4 4 4 4 4 4 4 4 4 4 3 2 
3 4 6 6 6 6 6 6 6 6 6 6 4 3 
4 6 8 8 8 8 8 8 8 8 8 8 6 4 
4 6 8 8 8 8 8 8 8 8 8 8 6 4
4 6 8 8 8 8 8 8 8 8 8 8 6 4
4 6 8 8 8 8 8 8 8 8 8 8 6 4
4 6 8 8 8 8 8 8 8 8 8 8 6 4
4 6 8 8 8 8 8 8 8 8 8 8 6 4
4 6 8 8 8 8 8 8 8 8 8 8 6 4
4 6 8 8 8 8 8 8 8 8 8 8 6 4
4 6 8 8 8 8 8 8 8 8 8 8 6 4
4 6 8 8 8 8 8 8 8 8 8 8 6 4 
3 4 6 6 6 6 6 6 6 6 6 6 4 3 
2 3 4 4 4 4 4 4 4 4 4 4 3 2 

*/

void solve() {
    int n;
    cin >> n;
    for (long long k = 1; k <= n; k++)
    {
        long long size = k * k;
        long long total_ways = size * (size-1) / 2;
        long long attacks = 0;
        attacks += 2 * 4;
        attacks += 3 * 8;
        attacks += 4 * (k - 3) * 4;
        attacks += 6 * (k - 4) * 4;
        attacks += 8 * (k - 4) * (k -4);
        attacks /= 2;
        cout << total_ways - attacks << '\n';
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