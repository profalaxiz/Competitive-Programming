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
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        if (name.size()) {
            freopen((name + ".in").c_str(), "r", stdin);
            freopen((name + ".out").c_str(), "w", stdout);
        }
    #endif
}

void solve() {
    
}

int main() {
    setIO("");
    auto start_time = chrono::high_resolution_clock::now();

    int t = 1;
    // cin >> t;
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