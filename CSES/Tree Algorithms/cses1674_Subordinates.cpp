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
    vector<vector<int>> adj(n + 1);
    vector<int> par(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }
    vector<int> ord;
    ord.push_back(1);
    for (int i = 0; i < (int)ord.size(); i++)
    {
        int u = ord[i];
        for (int v: adj[u]) ord.push_back(v);
    }
    vector<int> dp(n + 1, 0);
    reverse(ord.begin(), ord.end());
    for (int u : ord)
    {
        for (int v: adj[u]) dp[u] += 1 + dp[v];
    }
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << '\n';

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}