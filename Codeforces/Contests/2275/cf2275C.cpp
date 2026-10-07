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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        int m = n - 4;
        vector<int> s(m);
        for (int i = 0; i < m; i++) s[i] = a[i] + a[i + 2] - a[i + 4];
        ll ans = 0;
        unordered_map<int, ll> freq;
        for (int i = 0; i < m; i++)
        {
            ans += freq[s[i]];
            if (i >= 2 && s[i] == s[i - 2]) ans--;
            if (i >= 4 && s[i] == s[i - 4]) ans--;
            freq[s[i]]++;
        }
        cout << ans << '\n';
    }

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}