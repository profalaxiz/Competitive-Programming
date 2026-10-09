#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    auto start = high_resolution_clock::now();

    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int& xi: x) cin >> xi;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 2, 0));
    if (x[0] == 0) 
    {
        for (int v = 1; v <= m; v++)
        {
            dp[1][v] = 1;
        }
    } else {
        dp[1][x[0]] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int v = 1; v <= m; v++)
        {
            if (x[i - 1] != 0 && x[i - 1] != v) continue;
            dp[i][v] = dp[i - 1][v - 1] + dp[i - 1][v] + dp[i - 1][v + 1];
            dp[i][v] %= MOD;
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++) res = (res + dp[n][i]) % MOD;
    cout << res << '\n';

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}