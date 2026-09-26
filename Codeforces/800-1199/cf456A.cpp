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
    if (n == 1)
    {
        cout << "Poor Alex" << '\n';
        return 0;
    }

    vector<pair<int,int>> p(n);
    for (auto& it: p) cin >> it.first >> it.second;

    sort(p.begin(), p.end());
    for (int i = 1; i < n; i++)
    {
        if (p[i].first != p[i - 1].first && p[i].second < p[i-1].second)
        {
            // cout << p[i - 1].first << " : " << p[i - 1].second << '\n';
            // cout << p[i].first << " : " << p[i].second << '\n';
            cout << "Happy Alex" << '\n';
            return 0;
        }
    }

    cout << "Poor Alex" << '\n';

    return 0;
}