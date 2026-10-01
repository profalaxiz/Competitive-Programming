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

    int t;
    cin >> t;
    while(t--)
    {
        ll n, k, maxT;
        cin >> n >> k >> maxT;
        vector<ll> a(n);
        for (ll& x : a) cin >> x;
        ll sum = 0;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= maxT) cnt++;
            else 
            {
                if (cnt >= k)
                {
                    ll c = cnt - k + 1;
                    sum += c*(c+1) / 2;
                }
                cnt = 0;
            }
        }  
        if (cnt >= k)
        {
            ll c = cnt - k + 1;
            sum += c*(c+1) / 2;
        }
        cout << sum << '\n';      
    }

    return 0;
}