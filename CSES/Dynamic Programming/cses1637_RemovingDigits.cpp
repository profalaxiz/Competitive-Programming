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

    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp > 0)
        {
            int d = temp % 10;
            if (d != 0)
            {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
            temp /= 10;
        }
    }
    cout << dp[n] << '\n';

    // greedy approach
    // int cnt = 0;
    // while (n > 0)
    // {
    //     int temp = n;
    //     int max_d = 0;
    //     while (temp > 0)
    //     {
    //         int d = temp % 10;
    //         max_d = max(max_d, d);
    //         temp /= 10;
    //     }
    //     n -= max_d;
    //     cnt++;
    // }
    // cout << cnt << '\n';


    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}