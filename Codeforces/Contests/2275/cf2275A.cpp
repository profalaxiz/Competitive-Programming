#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;

void solve() {
    int x0, y0, R;
    cin >> x0 >> y0 >> R;
    cout << x0 + R << " " << y0 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}