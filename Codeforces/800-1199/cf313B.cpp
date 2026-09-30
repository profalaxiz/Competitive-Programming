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

    string s;
    cin >> s;
    int n = s.length();
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        // pref[i] = number of equal adjacent pairs among positions before i, [0...i-1]
        pref[i + 1] = pref[i] + (s[i] == s[i + 1]);
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << "index = " << i << " : answer = " << pref[i] << '\n';
    // }
    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r - 1] - pref[l - 1] << '\n';
    }
    


    return 0;
}