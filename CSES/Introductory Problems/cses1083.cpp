#include <bits/stdc++.h>
using namespace std;

#define all(x)  (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;
    vector<int> v(n - 1);
    for (auto& x: v) cin >> x;

    sort(all(v));
    for (int i = 1; i <= n; i++)
    {
        if (v[i - 1] != i)
        {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}