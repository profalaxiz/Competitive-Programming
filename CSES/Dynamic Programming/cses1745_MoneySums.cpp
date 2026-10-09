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
    vector<int> x(n);
    ll tot = 0;
    for (int& xi: x)
    {
        cin >> xi;
        tot += xi;
    }
    vector<bool> dp(tot + 1, false);
    dp[0] = true;
    for (int c: x)
    {
        for (int s = tot; s >= c; s--) dp[s] = dp[s] || dp[s - c];
    }
    vector<int> ans;
    for (int s = 1; s <= tot; s++)
    {
        if (dp[s]) ans.push_back(s);
    }
    cout << ans.size() << '\n';
    for (int s: ans) cout << s << " ";

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}