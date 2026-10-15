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

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    int room_count = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                room_count++;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '#';
                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int d = 0; d < 4; ++d) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.') {
                            grid[nr][nc] = '#'; 
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }
    cout << room_count << "\n";

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}