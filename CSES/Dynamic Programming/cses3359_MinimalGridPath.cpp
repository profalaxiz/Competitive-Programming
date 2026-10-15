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

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<int> frontier = {0};
    string ans;
    ans += grid[0][0];
    for (int k = 1; k <= 2 * n - 2; k++) {
        char best = 'Z';
        for (int i : frontier) {
            int j = (k - 1) - i;
            if (i + 1 < n) best = min(best, grid[i + 1][j]);
            if (j + 1 < n) best = min(best, grid[i][j + 1]);
        }
        vector<int> next;
        vector<bool> seen(n, false);
        for (int i : frontier) {
            int j = (k - 1) - i;
            if (i + 1 < n && grid[i + 1][j] == best && !seen[i + 1]) {
                seen[i + 1] = true;
                next.push_back(i + 1);
            }
            if (j + 1 < n && grid[i][j + 1] == best && !seen[i]) {
                seen[i] = true;
                next.push_back(i);
            }
        }
        ans += best;
        frontier = move(next);
    }
    cout << ans << '\n';

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}