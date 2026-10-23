#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;

const int MOD = 1e9 + 7;

struct Node 
{
    int nxt[26] = {};
    bool end = false;
};

vector<Node> trie(1);

void insert(const string& s)
{
    int u = 0;
    for (char c: s)
    {
        int x = c - 'a';
        if (!trie[u].nxt[x])
        {
            trie[u].nxt[x] = trie.size();
            trie.emplace_back();
        }
        u = trie[u].nxt[x];
    }
    trie[u].end = true;
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

    string s;
    cin >> s;
    int k;
    cin >> k;
    while (k--)
    {
        string w;
        cin >> w;
        insert(w);
    }

    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == 0) continue;
        int u = 0;
        for (int j = i; j < n; j++)
        {
            int x = s[j] - 'a';
            if (!trie[u].nxt[x]) break;
            u = trie[u].nxt[x];
            if (trie[u].end)
            {
                dp[j + 1] += dp[i];
                if (dp[j + 1] >= MOD) dp[j + 1] -= MOD;
            }
        }
    }

    cout << dp[n] << '\n';

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";

    return 0;
}