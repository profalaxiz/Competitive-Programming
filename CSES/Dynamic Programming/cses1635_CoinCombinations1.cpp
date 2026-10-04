#include<bits/stdc++.h>
using namespace std;
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

    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (auto& c: coins) cin >> c;


    // dp[i] = number of distinct ways to make sum i
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (auto c: coins)
        {
            if (i - c >= 0)
            {
                dp[i] = (dp[i] + dp[i - c]) % MOD;
            }
        }
    }

    cout << dp[x] << '\n';

    return 0;
}