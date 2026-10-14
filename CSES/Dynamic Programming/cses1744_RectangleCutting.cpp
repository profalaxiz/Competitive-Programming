#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    auto start = high_resolution_clock::now();

    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INF));
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j) 
            {
                dp[i][j] = 0;
                continue;
            }
            for (int x = 1; x < i; x++)
            {
                dp[i][j] = min(dp[i][j], dp[x][j] + dp[i - x][j] + 1);
            }
            for (int y = 1; y < j; y++)
            {
                dp[i][j] = min(dp[i][j], dp[i][y] + dp[i][j - y] + 1);
            }
        }
    }    
    cout << dp[a][b] << '\n';

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}