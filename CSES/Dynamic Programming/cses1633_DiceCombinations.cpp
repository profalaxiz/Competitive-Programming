#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

vector<ll> memo;
ll solve(int x)
{
    if (x == 0) return 1;
    if (x < 0) return 0;
    if (memo[x] != -1) return memo[x];
    ll ways = 0;
    for (int dice = 1; dice <= 6; dice++)
    {
        ways = (ways + solve(x - dice)) % MOD;
    }
    return memo[x] = ways;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; 
    cin >> n;
    // vector<ll> dp(n + 1);
    // dp[0] = 1;
    // for (int x = 1; x <= n; x++)
    // {
    //     for (int d = 1; d <= 6; d++)
    //     {
    //         if (x - d >= 0)
    //         {
    //             dp[x] += dp[x - d];
    //             dp[x] %= MOD;
    //         }
    //     }
    // }
    // cout << dp[n] << '\n';

    memo.assign(n + 1, -1);
    cout << solve(n) << '\n';

    return 0;
}