#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <chrono>

using namespace std;

// Types & Containers
using ll = long long;
using str = string;
using vi = vector<int>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using si = set<int>;

// Macros
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define del(x, i) erase(begin(x)+i)
#define rem(x,i) erase(begin(x), begin(x)+i)
#define mp make_pair

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define each_perm(x) sort(all(x)); do
#define end_perm(x) while(next_permutation(all(x))) 

// Loops
#define Trav(a,x) for (auto& a: x)
#define For(i,a,b) for (int i = (a); i < (b); ++i)

void setIO(string name = "") {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vpi deck(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int c; cin >> c;
        deck[i] = {c, p == i + 1 ? 1 : 0};
    }
    while (m >= 0)
    {
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (deck[i].second == 1)
            {
                idx = i; 
                break;
            }
        }
        if (idx < k)
        {
            if (m >= deck[idx].first)
            {
                m -= deck[idx].first;
                res++;
                pi tmp = deck[idx];
                deck.erase(deck.begin() + idx);
                deck.push_back(tmp);
            } else break;
        }
        else {
            int min_cost = 1e9, min_idx = -1;
            for (int i = 0; i < k; i++)
            {
                if (deck[i].first < min_cost)
                {
                    min_cost = deck[i].first;
                    min_idx = i;
                }
            }
            if (m >= min_cost)
            {
                m -= min_cost;
                pi tmp = deck[min_idx];
                deck.erase(deck.begin() + min_idx);
                deck.push_back(tmp);
            } else break;
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // setIO("");

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    auto start_time = chrono::high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    auto end_time = chrono::high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
        chrono::duration<double, milli> duration = end_time - start_time;
        cerr << "\n--- Execution Time: " << fixed << setprecision(2) << duration.count() << " ms ---" << endl;
    #endif
    return 0;
}