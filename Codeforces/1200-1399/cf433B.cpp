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

    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        pref[i] = pref[i - 1] + v[i];
    }
    sort(v.begin(), v.end());
    vector<ll> sorted_pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        sorted_pref[i] = sorted_pref[i - 1] + v[i];
    }

    int m;
    cin >> m;
    while(m--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            cout << pref[r] - pref[l - 1] << '\n';
        }
        else 
        {
            cout << sorted_pref[r] - sorted_pref[l - 1] << '\n';
        }
    }


    return 0;
}