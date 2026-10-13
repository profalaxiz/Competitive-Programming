#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
const int INF = 1e9;

int lcs(int n, int m, vector<int>& a, vector<int>& b,vector<vector<int>>& memo)
{
    if (n == 0 || m == 0) return 0;
    if (memo[n][m] != INF) 
    {
        return memo[n][m];
    }
    if (a[n - 1] == b[m - 1]) 
    {
        return memo[n][m] = lcs(n - 1, m - 1, a, b, memo) + 1;
    }
    else {
        return memo[n][m] = max(lcs(n - 1, m, a, b, memo), lcs(n, m - 1, a, b, memo));
    }
}

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
    vector<int> a(n);
    vector<int> b(m);
    for(int& ai: a) cin >> ai;
    for(int& bi: b) cin >> bi;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    vector<int> res;
    int i = n, j = m;
    int ans = lcs(n, m, a, b, dp);
    cout << ans << '\n';
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            res.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (lcs(i - 1, j, a, b, dp) > lcs(i, j - 1, a, b, dp)) i--;
        else j--;
    }
    reverse(res.begin(), res.end());
    for (int x: res) cout << x << " ";

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}