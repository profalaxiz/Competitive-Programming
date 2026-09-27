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

    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    for (auto& x: a) cin >> x;

    double res;
    if(n == 1)
    {
        res = max((a[0]-0),(l-a[0]));
        printf("%.9f", res);
        return 0;
    }

    sort(a.begin(), a.end());
    res = (double) a[0] - 0;  // dist from 0 to first lantern
    for (int i = 0; i < n - 1; i++)
    {
        double dist = a[i + 1] - a[i];  // dist from latern i to next lantern
        res = max(res, (double) dist/2);  // find the largest half distance between two lanterns
    }
    res = max(res, (double) l - a[n - 1]); // dist from last lantern to L
    printf("%.9f", res);

    return 0;
}