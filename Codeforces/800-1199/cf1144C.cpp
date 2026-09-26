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
    unordered_map<int,int> mp;
    for (auto& x: a) { 
        cin >> x;
        mp[x]++;
    }
    if (n == 1)
    {
        cout << "YES" << '\n';
        cout << 1 << '\n';
        cout << a[0] << "\n";
        cout << 0 << '\n';
        cout << '\n';
        return 0;
    }

    for (int x: a) // O(n)
    {
        if (mp[x] > 2) // O(1)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << '\n';
    vector<int> inc, dec;
    for (auto x: a)
    {
        if (mp[x] != 0) { 
            inc.push_back(x);
            mp[x]--;
        }
        if (mp[x] != 0) {
            dec.push_back(x);
            mp[x]--;
        } 
    }
    cout << inc.size() << '\n';
    sort(inc.begin(), inc.end());
    for (int x: inc) cout << x << " ";
    cout << '\n';
    cout << dec.size() << '\n';
    sort(dec.rbegin(), dec.rend());
    for (int x: dec) cout << x << " ";
    cout << '\n';

    return 0;
}