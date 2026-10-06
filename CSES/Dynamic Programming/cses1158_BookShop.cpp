#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    auto start = high_resolution_clock::now();

    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    // dp[i][j] -> max pages using of first i books with max price j
    // vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    // for (int i = 1; i <= n; i++)
    // {
    //     int price = prices[i - 1];
    //     int p = pages[i - 1];
    //     for (int j = 0; j <= x; j++)
    //     {
    //         dp[i][j] = dp[i - 1][j];
    //         if (j >= price)
    //         {
    //             dp[i][j] = max(dp[i][j], p + dp[i - 1][j - price]);
    //         }
    //     }
    // }
    // cout << dp[n][x] << '\n';

    //  dp[i] = maximum pages we can get with budget ≤ i
    vector<int> dp(x + 1, 0);
    for (int book = 0; book < n; book++)
    {
        for (int i = x; i >= prices[book]; --i)
        {
            dp[i] = max(dp[i], dp[i - prices[book]] + pages[book]);
        }
    }
    cout << dp[x] << '\n';

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}