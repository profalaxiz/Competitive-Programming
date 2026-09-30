#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k, q;
    cin >> n >> k >> q;
    const int max_T = 200000;
    vector<int> diff(max_T + 2, 0);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    vector<int> cnt(max_T + 2, 0);
    for (int i = 1; i <= max_T; i++) {
        cnt[i] = cnt[i - 1] + diff[i];
    }

    vector<int> pref(max_T + 2, 0);
    for (int i = 1; i <= max_T; i++)
    {
        pref[i] = pref[i - 1];
        if (cnt[i] >= k) pref[i]++;
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << '\n';
    }

    return 0;
}