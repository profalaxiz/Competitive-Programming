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

    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    vector<int> reps;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        reps.push_back(i);
        stack<int> st;
        st.push(i);
        vis[i] = 1;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            for (int v : adj[u]) {
                if (vis[v]) continue;
                vis[v] = 1;
                st.push(v);
            }
        }
    }
    cout << reps.size() - 1 << '\n';
    for (int i = 1; i < (int)reps.size(); i++) {
        cout << reps[i - 1] << ' ' << reps[i] << '\n';
    }

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}