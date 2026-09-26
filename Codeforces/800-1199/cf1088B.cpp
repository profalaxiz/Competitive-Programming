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

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end()); // n logn
    ll min = 0, sum = 0;
    
    for (int i = 0; i < n; i++)  // k
    {
        if (k <= 0) break;
        if (a[i] - sum <= 0) continue;
        min = a[i] - sum;
        cout << min << '\n';
        sum += min;
        k--;
    }

    while (k--) cout << 0 << '\n';


    // time complexity - O(n log n)


    return 0;
}