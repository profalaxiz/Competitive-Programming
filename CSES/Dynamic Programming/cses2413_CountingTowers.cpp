#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6;

ll a[MAXN + 1], b[MAXN + 1];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    auto start = high_resolution_clock::now();

    a[1] = 1;
    b[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        a[i] = (2 * a[i - 1] + b[i - 1]) % MOD;
        b[i] = (a[i - 1] + 4 * b[i - 1]) % MOD;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << (a[n] + b[n]) % MOD << '\n';
    }

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}