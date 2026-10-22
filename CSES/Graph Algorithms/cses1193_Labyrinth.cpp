#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;

int n, m;
vector<string> g;
vector<vector<char>> par;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    auto start = high_resolution_clock::now();

    cin >> n >> m;
    g.resize(n);
    par.assign(n, vector<char>(m, 0));

    pair<int, int> A, B;

    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') A = {i, j};
            if (g[i][j] == 'B') B = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(A);
    par[A.first][A.second] = 'S';

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (make_pair(x, y) == B) break;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (g[nx][ny] == '#' || par[nx][ny])
                continue;

            par[nx][ny] = dir[k];
            q.push({nx, ny});
        }
    }

    if (!par[B.first][B.second]) {
        cout << "NO\n";
        return 0;
    }

    string path;
    auto [x, y] = B;

    while (make_pair(x, y) != A) {
        char c = par[x][y];
        path += c;

        if (c == 'U') x++;
        else if (c == 'D') x--;
        else if (c == 'L') y++;
        else if (c == 'R') y--;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path << '\n';

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}