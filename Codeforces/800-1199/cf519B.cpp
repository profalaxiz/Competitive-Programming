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
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    vector<int> b(n-1);
    for (auto& x: b) cin >> x;
    vector<int> c(n-2);
    for (auto& x: c) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] != a[i])
        {
            cout << a[i] << '\n';
            flag1 = true;
            break;
        }
    }
    if (!flag1) cout << a[n - 1] << '\n';
    
    for (int i = 0; i < n - 2; i++)
    {
        if (c[i] != b[i])
        {
            cout << b[i] << '\n';
            flag2 = true;
            break;
        }
    }
    if (!flag2) cout << b[n - 2] << '\n';


    return 0;   
}