#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e9;
// vector<ll> memo;
// ll solve(int x, const vector<int>& coins)
// {
//     if (x < 0) return INF;
//     if (x == 0) return 0;
//     if (memo[x] != INF) return memo[x];
//     ll min_ways = INF;
//     for (int sum = 1; sum <= x; sum++)
//     {
//         for (int coin : coins)
//         {
//             if (x - coin >= 0) min_ways = min(min_ways, solve(x - coin, coins) + 1);
//         }
//     }
//     return memo[x] = min_ways;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    if (dp[x] == INF) cout << -1 << '\n';
    else cout << dp[x] << '\n';

    // memo.assign(x + 1, INF);
    // ll ans = solve(x, coins);
    // cout << (ans >= INF ? -1 : ans) << '\n';

    return 0;
}