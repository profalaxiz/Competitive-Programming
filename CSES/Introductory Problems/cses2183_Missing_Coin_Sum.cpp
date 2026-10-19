#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    auto start = high_resolution_clock::now();

    int n;
    cin >> n;
    vector<long long> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    sort(coins.begin(), coins.end());
    long long smallest_missing = 1;
    for (int i = 0; i < n; ++i) {
        if (coins[i] > smallest_missing) {
            break;
        }
        smallest_missing += coins[i];
    }
    cout << smallest_missing << "\n";

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}