#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll h, const vector<ll>& a, ll x)
{
    ll total = 0;
    for (ll c: a)   // O(n) worst case
    {
        if (h >= c)
        {
            total += h - c;
        }
        if (total > x) return false;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--)  // O(t)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (auto& y: a) cin >> y;  
        ll left = 0, right = 2e9;
        while (left < right)  // O(n log(right - left)) = O(n log(2e9))
        {
            ll h = left + (right - left + 1) / 2;
            if (check(h, a, x)) left = h;   // O(n)
            else right = h - 1;
        }
        cout << left << '\n';
    }

    return 0;
}